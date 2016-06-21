#include "putty.h"
#include "localization.h"


struct localization_table
{
	char *text;
	wchar_t *localization_text;
};


struct localization_table table[] = {
	{ "Cate&gory:" , L"분류(&G):" },
	{ "Session" , L"세션" },
	{ "Window" , L"창" },
	{ "Logging" , L"로깅" },
	{ "&Load" , L"불러오기(&L)" },
	{ "Always overwrite it", L"항상 덮어쓰기" },
};

const wchar_t* get_localization_text(const char* text)
{
	if (text == NULL)
	{
		return 0;
	}

	int length = sizeof(table) / sizeof(struct localization_table);
	for (int i = 0; i < length; i++)
	{
		if (strcmp(text, table[i].text) == 0)
		{
			return table[i].localization_text;
		}
	}

	return 0;
}