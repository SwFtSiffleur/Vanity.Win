#pragma once

#ifndef GRAPHICS_API
#define GRAPHICS_API

#include "../utils/common.hpp"

using WndProcCallback = std::function<bool(HWND, UINT, WPARAM, LPARAM)>;

LPDIRECT3D9 g_pD3D;
LPDIRECT3DDEVICE9 g_pd3dDevice;
D3DPRESENT_PARAMETERS g_d3dpp;
HWND g_hwnd;
WndProcCallback g_wndProcCallback;

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

namespace GAPI {
	bool CreateDeviceD3D();
	void CleanupDeviceD3D();
	void ResetDevice();
	LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

	void MakeWindow(const wchar_t* szWindowTitle,
		const wchar_t* szWindowClass,
		const ImVec2& size,
		WndProcCallback callback,
		Callback init,
		Callback render
	) {
		g_wndProcCallback = callback;

		WNDCLASSEX wc = { sizeof(WNDCLASSEX), CS_CLASSDC, WndProc, 0L, 0L, GetModuleHandle(0), 0, 0, 0, 0, szWindowClass, 0 };
		::RegisterClassEx(&wc);

		g_hwnd = ::CreateWindow(wc.lpszClassName, szWindowTitle, WS_POPUP, 100, 100, size.x, size.y, 0, 0, wc.hInstance, 0);

		if (!CreateDeviceD3D()) {
			CleanupDeviceD3D();
			::UnregisterClass(wc.lpszClassName, wc.hInstance);
			Utils::Error("Failed to create D3D device");
			return;
		}

		::ShowWindow(g_hwnd, SW_SHOWDEFAULT);
		::UpdateWindow(g_hwnd);

		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGui::StyleColorsDark();
		ImGui_ImplWin32_Init(g_hwnd);
		ImGui_ImplDX9_Init(g_pd3dDevice);

		init();

		MSG msg;
		ZeroMemory(&msg, sizeof(msg));
		while (msg.message != WM_QUIT) {
			if (::PeekMessage(&msg, 0, 0U, 0U, PM_REMOVE)) {
				::TranslateMessage(&msg);
				::DispatchMessage(&msg);
				continue;
			}

			ImGui_ImplDX9_NewFrame();
			ImGui_ImplWin32_NewFrame();
			ImGui::NewFrame();

			render();

			ImGui::EndFrame();
			g_pd3dDevice->SetRenderState(D3DRS_ZENABLE, FALSE);
			g_pd3dDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
			g_pd3dDevice->SetRenderState(D3DRS_SCISSORTESTENABLE, FALSE);

			D3DCOLOR bgScene = D3DCOLOR_RGBA(255, 255, 255, 255);
			g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, bgScene, 1.0f, 0);

			if (g_pd3dDevice->BeginScene() >= 0) {
				ImGui::Render();
				ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
				g_pd3dDevice->EndScene();
			}

			HRESULT result = g_pd3dDevice->Present(0, 0, 0, 0);
			if (result == D3DERR_DEVICELOST && g_pd3dDevice->TestCooperativeLevel() == D3DERR_DEVICENOTRESET)
				ResetDevice();
		}

		ImGui_ImplDX9_Shutdown();
		ImGui_ImplWin32_Shutdown();
		ImGui::DestroyContext();

		CleanupDeviceD3D();
		::DestroyWindow(g_hwnd);
		::UnregisterClass(wc.lpszClassName, wc.hInstance);
	}

	bool CreateDeviceD3D() {
		if ((g_pD3D = Direct3DCreate9(D3D_SDK_VERSION)) == NULL)
			return false;

		ZeroMemory(&g_d3dpp, sizeof(g_d3dpp));
		g_d3dpp.Windowed = TRUE;
		g_d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
		g_d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
		g_d3dpp.EnableAutoDepthStencil = TRUE;
		g_d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
		g_d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_ONE;

		if (g_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, g_hwnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &g_d3dpp, &g_pd3dDevice) < 0)
			return false;

		return true;
	}

	void CleanupDeviceD3D() {
		if (g_pd3dDevice) { g_pd3dDevice->Release(); g_pd3dDevice = 0; }
		if (g_pD3D) { g_pD3D->Release(); g_pD3D = 0; }
	}

	void ResetDevice() {
		ImGui_ImplDX9_InvalidateDeviceObjects();
		HRESULT hr = g_pd3dDevice->Reset(&g_d3dpp);
		if (hr == D3DERR_INVALIDCALL)
			IM_ASSERT(0);
		ImGui_ImplDX9_CreateDeviceObjects();
	}

	LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
		if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
			return true;

		switch (msg) {
		case WM_SIZE:
			if (g_pd3dDevice != NULL && wParam != SIZE_MINIMIZED) {
				g_d3dpp.BackBufferWidth = LOWORD(lParam);
				g_d3dpp.BackBufferHeight = HIWORD(lParam);
				ResetDevice();
			}
			return 0;

		case WM_SYSCOMMAND:
			if ((wParam & 0xfff0) == SC_KEYMENU) // disable alt key
				return 0;
			break;

		case WM_DESTROY:
			::PostQuitMessage(0);
			return 0;
		}

		if (g_wndProcCallback(hWnd, msg, wParam, lParam))
			return ::DefWindowProc(hWnd, msg, wParam, lParam);
		return {};
	}

	ImVec2 GetWindowSize() {
		return { (float)g_d3dpp.BackBufferWidth, (float)g_d3dpp.BackBufferHeight };
	}

	void SetWindowSize(const ImVec2& size) {
		g_d3dpp.BackBufferWidth = size.x;
		g_d3dpp.BackBufferHeight = size.y;
	}

	void SetWindowPos(const ImVec2& pos) {
		auto size = GetWindowSize();
		MoveWindow(g_hwnd, pos.x, pos.y, size.x, size.y, FALSE);
	}

	void DragWindow(const ImVec2& dragOffset) {
		RECT rect;
		if (!GetWindowRect(g_hwnd, &rect))
			return;

		ImVec2 newPos = { rect.left + dragOffset.x, rect.top + dragOffset.y };
		SetWindowPos(newPos);
	}
}

#endif // !GRAPHICS_API


