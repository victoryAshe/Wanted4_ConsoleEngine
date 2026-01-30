#pragma once

#include "Util/Util.h"
#include <iostream>
#include <vector>

namespace Wanted
{
	/*
	// Renderer가 Actor를 돌면서 Render 
	 : 이해를 돕기 위한 struct.
	struct RenderCommand
	{
		// 그리는 데 필요한 데이터
		Vector2 position;
		Color color = Color::White;
		char image = ' ';
	};
	*/

	// DLL 내부에서만 사용하도록.
	class Renderer
	{
	public:
		// 그리기 함수.
		static void Draw(const char image)
		{
			/*
			// Actor를 순회하면서 Render하는 예.
			for(auto& command: commands)
			{
				Draw(command.position, command.color,
					command.image);
			}
			*/

			std::cout << image;
		}

		// 위치 설정 및 그리기 한 번에 처리하는 함수.
		static void Draw(const Vector2& position, const char image)
		{
			Util::SetConsolePosition(position);
			Draw(image);
		}

		// 위치, 색상 설정 및 그리기.
		// Color는 size 크지 않아서 그냥 값 복사.
		static void Draw(
			const Vector2& position,
			Color color,
			const char image)
		{
			// Set Cursor Position.
			Util::SetConsolePosition(position);

			// Set Text Color.
			Util::SetConsoleTextColor(color);

			// Print Character.
			Draw(image);

			// 원래 색상으로 다시 설정 (흰색으로).
			Util::SetConsoleTextColor(Color::White);
		}


	private:
		/*
		static std::vector<RenderCommand> commands;
		*/
	};
}