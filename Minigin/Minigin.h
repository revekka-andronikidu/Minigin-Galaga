#pragma once
#include <string>
#include <functional>


namespace dae
{
	class Minigin
	{
	public:
		explicit Minigin(const std::string& dataPath);
		~Minigin();
		void Run(const std::function<void()>& load);
		/*constfloat GetWindowWidth() const;*/

		Minigin(const Minigin& other) = delete;
		Minigin(Minigin&& other) = delete;
		Minigin& operator=(const Minigin& other) = delete;
		Minigin& operator=(Minigin&& other) = delete;

	private:
		const int m_fixedUpdateFramerate{ 60 };
		const float m_fixed_time_step{ 1.f / m_fixedUpdateFramerate };
	};
}