/*MIT License

C++ 3D Game Tutorial Series (https://github.com/PardCode/CPP-3D-Game-Tutorial-Series)

Copyright (c) 2019-2022, PardCode

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.*/

#pragma once
#include <DX3D/Prerequisites.h>
#include <DX3D/Math/Rect.h>

class SwapChain
{
public:
	//Initialize SwapChain for a window
	SwapChain(void* hwnd,const Rect& size,RenderSystem * system);
	~SwapChain();

	void setFullScreen(bool fullscreen, const Rect& size);
	void resize( const Rect& size);
	bool present(bool vsync);
private:
	void reloadBuffers(unsigned int width, unsigned int height);
private:
	Microsoft::WRL::ComPtr < IDXGISwapChain> m_swap_chain = nullptr;
	Microsoft::WRL::ComPtr < ID3D11RenderTargetView> m_rtv = nullptr;
	Microsoft::WRL::ComPtr < ID3D11DepthStencilView> m_dsv = nullptr;
	RenderSystem * m_system = nullptr;

private:
	friend class RenderSystem;
};

