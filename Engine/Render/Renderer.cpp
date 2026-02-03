#include "Renderer.h"
#include "ScreenBuffer.h"
#include "Util/Util.h"

namespace Wanted
{
	Renderer::Frame::Frame(int bufferCount)
	{
		// 배열 생성 및 초기화.
		charInfoArray = new CHAR_INFO[bufferCount];
		memset(charInfoArray, 0, sizeof(CHAR_INFO) * bufferCount);
		//ZeroMemory(charInfoArray, sizeof(CHAR_INFO) * bufferCount); // 위와 동일한 기능.

		sortingOrderArray = new int[bufferCount];
		memset(sortingOrderArray, 0, sizeof(int) * bufferCount);
	}

	Renderer::Frame::~Frame()
	{
		SafeDeleteArray(charInfoArray);
		SafeDeleteArray(sortingOrderArray);
	}

	void Renderer::Frame::Clear(const Vector2& screenSize)
	{
		// 2차원 배열로 다루는 1차원 배열을 순회하면서
		// 빈 문자(' ')를 설정!
		const int width = screenSize.x;
		const int height = screenSize.y;
		for (int y = 0; y < height; ++y)
		{
			for (int x = 0; x < width; ++x)
			{
				// 배열 index 구하기.
				const int index = (y * width) + x;

				// 글자 값 및 속성 설정.
				CHAR_INFO& info = charInfoArray[index];
				info.Char.AsciiChar = ' ';
				info.Attributes = 0;

				// sortingOrder 초기화.
				sortingOrderArray[index] = -1;
			}
		}
	}

	// ==================== Frame ============================ //
	
	// 정적 변수 초기화.
	Renderer* Renderer::instance = nullptr;
	
	Renderer::Renderer(const Vector2& screenSize)
		: screenSize(screenSize)
	{
		instance = this;

		// Create instance of Frame struct
		const int bufferCount = screenSize.x * screenSize.y;
		frame = new Frame(bufferCount);

		// Initialize frame.
		frame->Clear(screenSize);

		// Create instance of Double Buffer
		screenBuffers[0] = new ScreenBuffer(screenSize);
		screenBuffers[0]->Clear();

		screenBuffers[1] = new ScreenBuffer(screenSize);
		screenBuffers[1]->Clear();
	}

	Renderer::~Renderer()
	{
		SafeDelete(frame);
		for (ScreenBuffer*& buffer : screenBuffers)
		{
			SafeDeleteArray(buffer);
		}
	}

	Renderer& Renderer::Get()
	{
		if (!instance)
		{
			MessageBoxA(
				nullptr,
				"Renderer::Get() - instance is null.",
				"Error",
				MB_OK
			);

			__debugbreak();
		}

		return *instance;
	}
	
	void Renderer::Draw()
	{
	}

	void Renderer::Submit(
		const char* text,
		const Vector2& position,
		Color color = Color::White,
		int sortingOrder = 0
	)
	{

	}

	void Renderer::Present()
	{
	}

	ScreenBuffer* Renderer::GetCurrentBuffer()
	{
	}
}