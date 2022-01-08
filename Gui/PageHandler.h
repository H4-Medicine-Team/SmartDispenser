#pragma once
#include "Page.h"

#include <memory>

namespace Gui {

	class PageHandler
	{
	public:
		// Get singleton instance of pagehandler
		static PageHandler& Get() { static PageHandler instance; return instance; }

		PageHandler(PageHandler const&) = delete;
		void operator=(PageHandler const&) = delete;

	private:
		PageHandler() : m_CurrentPage(NULL) {}

		~PageHandler() {
		}

	public:
		// Load a page, by giving it a page::T
		template <typename T, typename ...Args>
		void Load(Args && ...args);

		// This method calls both update and draw
		inline void Loop() {
			m_CurrentPage->Update();

			ClearBackground(m_CurrentPage->GetBackgroundColor());
			m_CurrentPage->Draw();
		}

	private:
		std::shared_ptr<Page> m_CurrentPage;
	};

	template<typename T, typename ...Args>
	inline void PageHandler::Load(Args && ...args) {
		m_CurrentPage = std::make_shared<T>(std::forward<Args>(args)...);
	}
}