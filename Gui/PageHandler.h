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
		template <typename T>
		void Load();

		// This method calls both update and draw
		inline void Loop() {
			m_CurrentPage->Update();

			ClearBackground(m_CurrentPage->GetBackgroundColor());
			m_CurrentPage->Draw();
		}

	private:
		std::shared_ptr<Page> m_CurrentPage;
	};

	template<typename T>
	inline void PageHandler::Load() {
		m_CurrentPage = std::make_shared<T>();
	}
}