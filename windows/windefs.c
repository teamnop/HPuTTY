/*
 * windefs.c: default settings that are specific to Windows.
 */

#include "putty.h"

#include <commctrl.h>

FontSpec *platform_default_fontspec(const char *name)
{
    OSVERSIONINFO versioninfo;
    versioninfo.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
    GetVersionEx(&versioninfo);

	int acp = GetACP();

	if (!strcmp(name, "Font")) {
		if (versioninfo.dwMajorVersion >= 6)
			return fontspec_new("Consolas", 0, 10, ANSI_CHARSET);
		else
			return fontspec_new("Courier New", 0, 10, ANSI_CHARSET);
	}
	else if (!strcmp(name, "FontUnicode") && acp == 949) { // code page가 한국어 일때만 나눔고딕 코딩으로 셋팅
		wchar_t *unicode_font = L"나눔고딕코딩";
		char* unicode_font_mb = short_wc_to_mb(acp, 0, unicode_font, wcslen(unicode_font), NULL, NULL);

		FontSpec* fontspec = fontspec_new(unicode_font_mb, 0, 10, HANGEUL_CHARSET);
		free(unicode_font_mb);

		return fontspec;
	}
	else {
		return fontspec_new("", 0, 0, 0);
	}
}

Filename *platform_default_filename(const char *name)
{
    if (!strcmp(name, "LogFileName"))
	return filename_from_str("putty.log");
    else
	return filename_from_str("");
}

char *platform_default_s(const char *name)
{
    if (!strcmp(name, "SerialLine"))
		return dupstr("COM1");
    return NULL;
}

int platform_default_i(const char *name, int def)
{
    if (!strcmp(name, "FontQuality"))
    {
        OSVERSIONINFO versioninfo;
        versioninfo.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
        GetVersionEx(&versioninfo);
        if (versioninfo.dwMajorVersion >= 6) 
            return FQ_CLEARTYPE;
    }
    return def;
}
