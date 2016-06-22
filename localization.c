#include "putty.h"

#include <commctrl.h>

#include "localization.h"

extern Conf *conf;

struct localization_table
{
	char *text;
	wchar_t *localization_text;
};


struct localization_table table[] = {
	{ "&Open", L"접속(&O)" },
	{ "&Cancel", L"취소(&C)" },
	{ "About", L"정보" },
	{ "Keygen", L"Keygen" },
	{ "Agent", L"Agent" },
	{ "Session", L"세션" },
	{ "Logging", L"로깅" },
	{ "Terminal", L"터미널" },
	{ "Keyboard", L"키보드" },
	{ "Bell", L"알림" },
	{ "Features", L"기능" },
	{ "Window", L"창" },
	{ "Appearance", L"모양새" },
	{ "Behaviour", L"행동" },
	{ "Translation", L"변환" },
	{ "Selection", L"선택" },
	{ "Colours", L"색상" },
	{ "Hyperlinks", L"하이퍼링크" },
	{ "Connection", L"연결" },
	{ "Data", L"데이터" },
	{ "Proxy", L"프록시" },
	{ "Telnet", L"텔텟" },
	{ "Rlogin", L"Rlogin" },
	{ "SSH", L"SSH" },
	{ "Kex", L"키 교환" },
	{ "Cipher", L"암호화" },
	{ "Auth", L"인증" },
	{ "GSSAPI", L"GSSAPI" },
	{ "TTY", L"TTY" },
	{ "X11", L"X11" },
	{ "Tunnels", L"터널" },
	{ "Bugs", L"버그 우회" },
	{ "More bugs", L"추가 버그 우회" },
	{ "Serial", L"시리얼" },
	{ "Cygterm", L"Cygterm" },
	{ "Host &Name (or IP address)", L"호스트 이름 또는 IP 주소(&N)" },
	{ "&Port", L"포트(&P)" },
	{ "Connection type:", L"연결 종류:" },
	{ "Ra&w", L"날(&W)" },
	{ "Ad&b", L"Ad&b" },
	{ "&Telnet", L"텔넷(&T)" },
	{ "Rlog&in", L"Rlog&in" },
	{ "&SSH", L"&SSH" },
	{ "Se&rial", L"시리얼(&R)" },
	{ "Cygterm", L"Cygterm" },
	{ "Specify the destination you want to connect to", L"연결 대상을 입력하세요" },
	{ "Sav&ed Sessions", L"저장된 세션(&E)" },
	{ "&Load", L"불러오기(&L)" },
	{ "Sa&ve", L"저장하기(&V)" },
	{ "&Delete", L"삭제하기(&D)" },
	{ "Sessions from registry", L"레지스트리에서 불러온 세션" },
	{ "Sessions from file", L"파일에서 불러온 세션" },
	{ "Load, save or delete a stored session", L"저장된 세션을 불러오거나, 저장하거나, 삭제합니다" },
	{ "Close window on e&xit:", L"종료시 창 닫기(&X):" },
	{ "Always", L"항상" },
	{ "Never", L"안함" },
	{ "Only on clean exit", L"깨끗한 종료일 때만" },
	{ "UI Language (requires restart):", L"언어 (재시작 필요):" },
	{ "English", L"English" },
	{ "Korean", L"한국어" },
	{ "Basic options for your PuTTY session", L"PuTTY 세션의 기본적인 옵션" },
	{ "Session logging:", L"세션 로깅:" },
	{ "None", L"안함" },
	{ "&Printable output", L"인쇄 가능한 출력(&P)" },
	{ "A&ll session output", L"모든 세션 출력(&L)" },
	{ "&SSH packets", L"SSH 패킷(&S)" },
	{ "SSH packets and &raw data", L"SSH 패킷과 날 데이터(&R)" },
	{ "Log &file name:", L"로그 파일 이름(&F):" },
	{ "Bro&wse...", L"찾아보기(&W)..." },
	{ "(Log file name can contain &&Y, &&M, &&D for date, &&T for", L"(Log file name can contain &&Y, &&M, &&D for date, &&T for" },
	{ "time, &&H for host name, and &&P for port number)", L"time, &&H for host name, and &&P for port number)" },
	{ "What to do if th&e log file already exists:", L"What to do if th&e log file already exists:" },
	{ "Always overwrite it", L"Always overwrite it" },
	{ "Always append to the end of it", L"Always append to the end of it" },
	{ "Ask the user every time", L"Ask the user every time" },
	{ "Fl&ush log file frequently", L"Fl&ush log file frequently" },
	{ "Omit &known password fields", L"Omit &known password fields" },
	{ "Omit session &data", L"Omit session &data" },
	{ "Options specific to SSH packet logging", L"Options specific to SSH packet logging" },
	{ "Options controlling session logging", L"Options controlling session logging" },
	{ "Auto &wrap mode initially on", L"Auto &wrap mode initially on" },
	{ "&DEC Origin Mode initially on", L"&DEC Origin Mode initially on" },
	{ "Implicit C&R in every LF", L"Implicit C&R in every LF" },
	{ "Implicit L&F in every CR", L"Implicit L&F in every CR" },
	{ "Us&e background colour to erase screen", L"Us&e background colour to erase screen" },
	{ "E&nable blinking text", L"E&nable blinking text" },
	{ "An&swerback to ^E:", L"An&swerback to ^E:" },
	{ "Set various terminal options", L"Set various terminal options" },
	{ "&Local echo:", L"&Local echo:" },
	{ "Auto", L"Auto" },
	{ "Force on", L"Force on" },
	{ "Force off", L"Force off" },
	{ "Local line edi&ting:", L"Local line edi&ting:" },
	{ "Auto", L"Auto" },
	{ "Force on", L"Force on" },
	{ "Force off", L"Force off" },
	{ "Line discipline options", L"Line discipline options" },
	{ "&Printer to send ANSI printer output to:", L"&Printer to send ANSI printer output to:" },
	{ "Remote-controlled printing", L"Remote-controlled printing" },
	{ "Options controlling the terminal emulation", L"Options controlling the terminal emulation" },
	{ "The &Backspace key", L"The &Backspace key" },
	{ "Control-H", L"Control-H" },
	{ "Control-? (127)", L"Control-? (127)" },
	{ "Th&e Home and End keys", L"Th&e Home and End keys" },
	{ "Standard", L"Standard" },
	{ "rxvt", L"rxvt" },
	{ "The &Function keys and keypad", L"The &Function keys and keypad" },
	{ "ESC[n~", L"ESC[n~" },
	{ "Linux", L"Linux" },
	{ "Xterm R6", L"Xterm R6" },
	{ "VT400", L"VT400" },
	{ "VT100+", L"VT100+" },
	{ "SCO", L"SCO" },
	{ "4690", L"4690" },
	{ "Change the sequences sent by:", L"Change the sequences sent by:" },
	{ "Initial state of cu&rsor keys:", L"Initial state of cu&rsor keys:" },
	{ "Normal", L"Normal" },
	{ "Application", L"Application" },
	{ "I&nitial state of numeric keypad:", L"I&nitial state of numeric keypad:" },
	{ "Normal", L"Normal" },
	{ "Application", L"Application" },
	{ "NetHack", L"NetHack" },
	{ "Application keypad settings:", L"Application keypad settings:" },
	{ "Al&tGr acts as Compose key", L"Al&tGr acts as Compose key" },
	{ "Control-Alt is &different from AltGr", L"Control-Alt is &different from AltGr" },
	{ "Right-A&lt acts as it is", L"Right-A&lt acts as it is" },
	{ "Set &meta bit on alt (instead of escape)", L"Set &meta bit on alt (instead of escape)" },
	{ "Enable extra keyboard features:", L"Enable extra keyboard features:" },
	{ "Options controlling the effects of keys", L"Options controlling the effects of keys" },
	{ "Action to happen when a &bell occurs:", L"Action to happen when a &bell occurs:" },
	{ "None (bell disabled)", L"None (bell disabled)" },
	{ "Make default system alert sound", L"Make default system alert sound" },
	{ "Visual bell (flash window)", L"Visual bell (flash window)" },
	{ "Beep using the PC speaker", L"Beep using the PC speaker" },
	{ "Play a custom sound file", L"Play a custom sound file" },
	{ "Custom sound file to play as a bell:", L"Custom sound file to play as a bell:" },
	{ "Bro&wse...", L"Bro&wse..." },
	{ "Taskbar/capt&ion indication on bell:", L"Taskbar/capt&ion indication on bell:" },
	{ "Disabled", L"Disabled" },
	{ "Flashing", L"Flashing" },
	{ "Steady", L"Steady" },
	{ "Set the style of bell", L"Set the style of bell" },
	{ "Bell is temporarily &disabled when over-used", L"Bell is temporarily &disabled when over-used" },
	{ "Over-use &means this many bells...", L"Over-use &means this many bells..." },
	{ "... in &this many seconds", L"... in &this many seconds" },
	{ "The bell is re-enabled after a few seconds of silence.", L"The bell is re-enabled after a few seconds of silence." },
	{ "&Seconds of silence required", L"&Seconds of silence required" },
	{ "Control the bell overload behaviour", L"Control the bell overload behaviour" },
	{ "Options controlling the terminal bell", L"Options controlling the terminal bell" },
	{ "Disable application c&ursor keys mode", L"Disable application c&ursor keys mode" },
	{ "Disable application &keypad mode", L"Disable application &keypad mode" },
	{ "Disable &xterm-style mouse reporting", L"Disable &xterm-style mouse reporting" },
	{ "Di&sable remote-controlled terminal resizing", L"Di&sable remote-controlled terminal resizing" },
	{ "Disable s&witching to alternate terminal screen", L"Disable s&witching to alternate terminal screen" },
	{ "Disable remo&te-controlled window title changing", L"Disable remo&te-controlled window title changing" },
	{ "Response to remote title &query (SECURITY):", L"Response to remote title &query (SECURITY):" },
	{ "None", L"None" },
	{ "Empty string", L"Empty string" },
	{ "Window title", L"Window title" },
	{ "Disa&ble destructive backspace on server sending ^?", L"Disa&ble destructive backspace on server sending ^?" },
	{ "Disable &remote-controlled character set configuration", L"Disable &remote-controlled character set configuration" },
	{ "Disab&le Arabic text shaping", L"Disab&le Arabic text shaping" },
	{ "&Disable bidirectional text display", L"&Disable bidirectional text display" },
	{ "Enabling and disabling advanced terminal features", L"Enabling and disabling advanced terminal features" },
	{ "Colu&mns", L"Colu&mns" },
	{ "&Rows", L"&Rows" },
	{ "When window is resi&zed:", L"When window is resi&zed:" },
	{ "Change the number of rows and columns", L"Change the number of rows and columns" },
	{ "Change rows and columns only when maximised", L"Change rows and columns only when maximised" },
	{ "Change the size of the font", L"Change the size of the font" },
	{ "Change font size only when maximised", L"Change font size only when maximised" },
	{ "Forbid resizing completely", L"Forbid resizing completely" },
	{ "Set the size of the window", L"Set the size of the window" },
	{ "Line&s of scrollback", L"Line&s of scrollback" },
	{ "Scro&llback lines at a time (-1 half, -2 full screen)", L"Scro&llback lines at a time (-1 half, -2 full screen)" },
	{ "&Display scrollbar", L"&Display scrollbar" },
	{ "D&isplay scrollbar in full screen mode", L"D&isplay scrollbar in full screen mode" },
	{ "Reset scrollbac&k on keypress", L"Reset scrollbac&k on keypress" },
	{ "Reset scrollback on dis&play activity", L"Reset scrollback on dis&play activity" },
	{ "Push &erased text into scrollback", L"Push &erased text into scrollback" },
	{ "Control the scrollback in the window", L"Control the scrollback in the window" },
	{ "Options controlling PuTTY's window", L"Options controlling PuTTY's window" },
	{ "Cursor appearance:", L"Cursor appearance:" },
	{ "B&lock", L"B&lock" },
	{ "&Underline", L"&Underline" },
	{ "&Vertical line", L"&Vertical line" },
	{ "Cursor &blinks", L"Cursor &blinks" },
	{ "Adjust the use of the cursor", L"Adjust the use of the cursor" },
	{ "Fo&nt used in the terminal window", L"Fo&nt used in the terminal window" },
	{ "Change...", L"Change..." },
	{ "Use separated unicode &font", L"Use separated unicode &font" },
	{ "Font for unicode characters", L"Font for unicode characters" },
	{ "Change...", L"Change..." },
	{ "Adjustment of unicode font (px)", L"Adjustment of unicode font (px)" },
	{ "Allow selection of variable-pitch fonts", L"Allow selection of variable-pitch fonts" },
	{ "Font &quality:", L"Font &quality:" },
	{ "Antialiased", L"Antialiased" },
	{ "Non-Antialiased", L"Non-Antialiased" },
	{ "ClearType", L"ClearType" },
	{ "Default", L"Default" },
	{ "Font settings", L"Font settings" },
	{ "Hide mouse &pointer when typing in window", L"Hide mouse &pointer when typing in window" },
	{ "Adjust the use of the mouse pointer", L"Adjust the use of the mouse pointer" },
	{ "Gap b&etween text and window edge:", L"Gap b&etween text and window edge:" },
	{ "&Sunken-edge border (slightly thicker)", L"&Sunken-edge border (slightly thicker)" },
	{ "Adjust the window border", L"Adjust the window border" },
	{ "Configure the appearance of PuTTY's window", L"Configure the appearance of PuTTY's window" },
	{ "Window &title:", L"Window &title:" },
	{ "Separate w&indow and icon titles", L"Separate w&indow and icon titles" },
	{ "Adjust the behaviour of the window title", L"Adjust the behaviour of the window title" },
	{ "&Warn before closing window", L"&Warn before closing window" },
	{ "Window closes on ALT-F&4", L"Window closes on ALT-F&4" },
	{ "Syste&m menu appears on ALT-Space", L"Syste&m menu appears on ALT-Space" },
	{ "System menu appears on A&LT alone", L"System menu appears on A&LT alone" },
	{ "&Ensure window is always on top", L"&Ensure window is always on top" },
	{ "&Full screen on Alt-Enter", L"&Full screen on Alt-Enter" },
	{ "Window / tray icon:", L"Window / tray icon:" },
	{ "Change Icon...", L"Change Icon..." },
	{ "Show tray icon:", L"Show tray icon:" },
	{ "&Normal", L"&Normal" },
	{ "Alwa&ys", L"Alwa&ys" },
	{ "Neve&r", L"Neve&r" },
	{ "On &start", L"On &start" },
	{ "Accept single-click to restore from tray", L"Accept single-click to restore from tray" },
	{ "Adjust the icon", L"Adjust the icon" },
	{ "Configure the behaviour of PuTTY's window", L"Configure the behaviour of PuTTY's window" },
	{ "&Remote character set:", L"&Remote character set:" },
	{ "(Codepages supported by Windows but not listed here,", L"(Codepages supported by Windows but not listed here," },
	{ "such as CP866 on many systems, can be entered", L"such as CP866 on many systems, can be entered" },
	{ "manually)", L"manually)" },
	{ "Character set translation", L"Character set translation" },
	{ "Treat CJK ambiguous characters as &wide", L"Treat CJK ambiguous characters as &wide" },
	{ "Cap&s Lock acts as Cyrillic switch", L"Cap&s Lock acts as Cyrillic switch" },
	{ "Handling of line drawing characters:", L"Handling of line drawing characters:" },
	{ "&Use Unicode line drawing code points", L"&Use Unicode line drawing code points" },
	{ "&Poor man's line drawing (+, - and |)", L"&Poor man's line drawing (+, - and |)" },
	{ "Font has &XWindows encoding", L"Font has &XWindows encoding" },
	{ "Use font in &both ANSI and OEM modes", L"Use font in &both ANSI and OEM modes" },
	{ "Us&e font in OEM mode only", L"Us&e font in OEM mode only" },
	{ "Copy an&d paste line drawing characters as lqqqk", L"Copy an&d paste line drawing characters as lqqqk" },
	{ "Adjust how PuTTY handles line drawing characters", L"Adjust how PuTTY handles line drawing characters" },
	{ "Options controlling character set translation", L"Options controlling character set translation" },
	{ "Action of &mouse buttons:", L"Action of &mouse buttons:" },
	{ "Default (Middle pastes, Right brings up menu)", L"Default (Middle pastes, Right brings up menu)" },
	{ "Windows (Middle extends, Right brings up menu)", L"Windows (Middle extends, Right brings up menu)" },
	{ "Compromise (Middle extends, Right pastes)", L"Compromise (Middle extends, Right pastes)" },
	{ "xterm (Middle pastes, Right extends)", L"xterm (Middle pastes, Right extends)" },
	{ "Shift overrides a&pplication's use of mouse", L"Shift overrides a&pplication's use of mouse" },
	{ "Detect &URLs on selection and launch in browser", L"Detect &URLs on selection and launch in browser" },
	{ "Default selection mode (Alt+drag does the other one):", L"Default selection mode (Alt+drag does the other one):" },
	{ "&Normal", L"&Normal" },
	{ "&Rectangular block", L"&Rectangular block" },
	{ "Paste to clipboard in RT&F as well as plain text", L"Paste to clipboard in RT&F as well as plain text" },
	{ "Paste Delay per Line (ms)", L"Paste Delay per Line (ms)" },
	{ "Control use of mouse", L"Control use of mouse" },
	{ "Charact&er classes:", L"Charact&er classes:" },
	{ "Se&t to class", L"Se&t to class" },
	{ "&Set", L"&Set" },
	{ "Control the select-one-word-at-a-time mode", L"Control the select-one-word-at-a-time mode" },
	{ "Options controlling copy and paste", L"Options controlling copy and paste" },
	{ "Allow term&inal to specify ANSI colours", L"Allow term&inal to specify ANSI colours" },
	{ "Allow terminal to use xterm &256-colour mode", L"Allow terminal to use xterm &256-colour mode" },
	{ "Indicate &bolded text by changing:", L"Indicate &bolded text by changing:" },
	{ "The font", L"The font" },
	{ "The colour", L"The colour" },
	{ "Both", L"Both" },
	{ "Attempt to use &logical palettes", L"Attempt to use &logical palettes" },
	{ "U&se system colours", L"U&se system colours" },
	{ "Window opaci&ty (50-255)", L"Window opaci&ty (50-255)" },
	{ "General options for colour usage", L"General options for colour usage" },
	{ "Select a colour from the list, and then click the Modify", L"Select a colour from the list, and then click the Modify" },
	{ "button to change its appearance.", L"button to change its appearance." },
	{ "Select a colo&ur to adjust:", L"Select a colo&ur to adjust:" },
	{ "RGB value:", L"RGB value:" },
	{ "&Red", L"&Red" },
	{ "Gree&n", L"Gree&n" },
	{ "Blu&e", L"Blu&e" },
	{ "&Modify", L"&Modify" },
	{ "Adjust the precise colours PuTTY displays", L"Adjust the precise colours PuTTY displays" },
	{ "Options controlling use of colours", L"Options controlling use of colours" },
	{ "Underline hyperlinks:", L"Underline hyperlinks:" },
	{ "Always", L"Always" },
	{ "When hovered upon", L"When hovered upon" },
	{ "Never", L"Never" },
	{ "Use ctr&l+click to launch hyperlinks", L"Use ctr&l+click to launch hyperlinks" },
	{ "General options for hyperlinks", L"General options for hyperlinks" },
	{ "Use the default &browser", L"Use the default &browser" },
	{ "or &specify an application to open hyperlinks with:", L"or &specify an application to open hyperlinks with:" },
	{ "Bro&wse...", L"Bro&wse..." },
	{ "Browser application", L"Browser application" },
	{ "URL selection:", L"URL selection:" },
	{ "Select sensible URLs", L"Select sensible URLs" },
	{ "Select nearly any URL", L"Select nearly any URL" },
	{ "Custom", L"Custom" },
	{ "Customise regex:", L"Customise regex:" },
	{ "Regular expression", L"Regular expression" },
	{ "Options controlling behaviour of hyperlinks", L"Options controlling behaviour of hyperlinks" },
	{ "Seconds between &keepalives (0 to turn off)", L"Seconds between &keepalives (0 to turn off)" },
	{ "Sending of null packets to keep session active", L"Sending of null packets to keep session active" },
	{ "Disab&le Nagle's algorithm (TCP_NODELAY option)", L"Disab&le Nagle's algorithm (TCP_NODELAY option)" },
	{ "Enable TC&P keepalives (SO_KEEPALIVE option)", L"Enable TC&P keepalives (SO_KEEPALIVE option)" },
	{ "Low-level TCP connection options", L"Low-level TCP connection options" },
	{ "A&uto", L"A&uto" },
	{ "IPv&4", L"IPv&4" },
	{ "IPv&6", L"IPv&6" },
	{ "Internet protocol version", L"Internet protocol version" },
	{ "Logical na&me of remote host (e.g. for SSH key lookup):", L"Logical na&me of remote host (e.g. for SSH key lookup):" },
	{ "Logical name of remote host", L"Logical name of remote host" },
	{ "Attempt to reconnect on connection &failure", L"Attempt to reconnect on connection &failure" },
	{ "Attempt to reconnect on system &wakeup", L"Attempt to reconnect on system &wakeup" },
	{ "Reconnect options", L"Reconnect options" },
	{ "Options controlling the connection", L"Options controlling the connection" },
	{ "A&uto-login username", L"A&uto-login username" },
	{ "Whe&n username is not specified:", L"Whe&n username is not specified:" },
	{ "Prompt", L"Prompt" },
	{ "Use system username", L"Use system username" },
	{ "Login details", L"Login details" },
	{ "&Terminal-type string", L"&Terminal-type string" },
	{ "Terminal &speeds", L"Terminal &speeds" },
	{ "Terminal details", L"Terminal details" },
	{ "&Variable", L"&Variable" },
	{ "Va&lue", L"Va&lue" },
	{ "A&dd", L"A&dd" },
	{ "&Remove", L"&Remove" },
	{ "Environment variables", L"Environment variables" },
	{ "Data to send to the server", L"Data to send to the server" },
	{ "Proxy &type:", L"Proxy &type:" },
	{ "None", L"None" },
	{ "SOCKS 4", L"SOCKS 4" },
	{ "SOCKS 5", L"SOCKS 5" },
	{ "HTTP", L"HTTP" },
	{ "Telnet", L"Telnet" },
	{ "Local", L"Local" },
	{ "Prox&y hostname", L"Prox&y hostname" },
	{ "&Port", L"&Port" },
	{ "&Exclude Hosts/IPs", L"&Exclude Hosts/IPs" },
	{ "Consider pro&xying local host connections", L"Consider pro&xying local host connections" },
	{ "&Do DNS name lookup at proxy end:", L"&Do DNS name lookup at proxy end:" },
	{ "No", L"No" },
	{ "Auto", L"Auto" },
	{ "Yes", L"Yes" },
	{ "&Username", L"&Username" },
	{ "Pass&word", L"Pass&word" },
	{ "Telnet co&mmand, or local proxy command", L"Telnet co&mmand, or local proxy command" },
	{ "Options controlling proxy usage", L"Options controlling proxy usage" },
	{ "Handling of OLD_ENVIRON ambiguity:", L"Handling of OLD_ENVIRON ambiguity:" },
	{ "&BSD (commonplace)", L"&BSD (commonplace)" },
	{ "R&FC 1408 (unusual)", L"R&FC 1408 (unusual)" },
	{ "&Telnet negotiation mode:", L"&Telnet negotiation mode:" },
	{ "Passive", L"Passive" },
	{ "Active", L"Active" },
	{ "&Keyboard sends Telnet special commands", L"&Keyboard sends Telnet special commands" },
	{ "Return key sends Telnet New Line instead of ^&M", L"Return key sends Telnet New Line instead of ^&M" },
	{ "Telnet protocol adjustments", L"Telnet protocol adjustments" },
	{ "Options controlling Telnet connections", L"Options controlling Telnet connections" },
	{ "&Local username:", L"&Local username:" },
	{ "Data to send to the server", L"Data to send to the server" },
	{ "Options controlling Rlogin connections", L"Options controlling Rlogin connections" },
	{ "&Remote command:", L"&Remote command:" },
	{ "Data to send to the server", L"Data to send to the server" },
	{ "Do&n't start a shell or command at all", L"Do&n't start a shell or command at all" },
	{ "&Enable compression", L"&Enable compression" },
	{ "Preferred SSH protocol version:", L"Preferred SSH protocol version:" },
	{ "1 on&ly", L"1 on&ly" },
	{ "&1", L"&1" },
	{ "&2", L"&2" },
	{ "2 onl&y", L"2 onl&y" },
	{ "Protocol options", L"Protocol options" },
	{ "&Share SSH connections if possible", L"&Share SSH connections if possible" },
	{ "Permitted roles in a shared connection:", L"Permitted roles in a shared connection:" },
	{ "&Upstream (connecting to the real server)", L"&Upstream (connecting to the real server)" },
	{ "&Downstream (connecting to the upstream PuTTY)", L"&Downstream (connecting to the upstream PuTTY)" },
	{ "Sharing an SSH connection between PuTTY tools", L"Sharing an SSH connection between PuTTY tools" },
	{ "Options controlling SSH connections", L"Options controlling SSH connections" },
	{ "Algorithm &selection policy:", L"Algorithm &selection policy:" },
	{ "&Up", L"&Up" },
	{ "&Down", L"&Down" },
	{ "Key exchange algorithm options", L"Key exchange algorithm options" },
	{ "Max minu&tes before rekey (0 for no limit)", L"Max minu&tes before rekey (0 for no limit)" },
	{ "Ma&x data before rekey (0 for no limit)", L"Ma&x data before rekey (0 for no limit)" },
	{ "(Use 1M for 1 megabyte, 1G for 1 gigabyte etc)", L"(Use 1M for 1 megabyte, 1G for 1 gigabyte etc)" },
	{ "Options controlling key re-exchange", L"Options controlling key re-exchange" },
	{ "Host keys or fingerprints to accept:", L"Host keys or fingerprints to accept:" },
	{ "&Remove", L"&Remove" },
	{ "&Key", L"&Key" },
	{ "Add ke&y", L"Add ke&y" },
	{ "Manually configure host keys for this connection", L"Manually configure host keys for this connection" },
	{ "Options controlling SSH key exchange", L"Options controlling SSH key exchange" },
	{ "Encryption cipher &selection policy:", L"Encryption cipher &selection policy:" },
	{ "&Up", L"&Up" },
	{ "&Down", L"&Down" },
	{ "Enable legacy use of s&ingle-DES in SSH-2", L"Enable legacy use of s&ingle-DES in SSH-2" },
	{ "Encryption options", L"Encryption options" },
	{ "Options controlling SSH encryption", L"Options controlling SSH encryption" },
	{ "&Bypass authentication entirely (SSH-2 only)", L"&Bypass authentication entirely (SSH-2 only)" },
	{ "&Display pre-authentication banner (SSH-2 only)", L"&Display pre-authentication banner (SSH-2 only)" },
	{ "Attem&pt authentication using Pageant", L"Attem&pt authentication using Pageant" },
	{ "Atte&mpt TIS or CryptoCard auth (SSH-1)", L"Atte&mpt TIS or CryptoCard auth (SSH-1)" },
	{ "Attempt \"keyboard - &interactive\" auth (SSH-2)", L"Attempt \"keyboard - &interactive\" auth (SSH-2)" },
	{ "Authentication methods", L"Authentication methods" },
	{ "Allow agent &forwarding", L"Allow agent &forwarding" },
	{ "Allow attempted changes of username in SSH-2", L"Allow attempted changes of username in SSH-2" },
	{ "Private &key file for authentication:", L"Private &key file for authentication:" },
	{ "Bro&wse...", L"Bro&wse..." },
	{ "Authentication parameters", L"Authentication parameters" },
	{ "Options controlling SSH authentication", L"Options controlling SSH authentication" },
	{ "A&ttempt GSSAPI authentication (SSH-2 only)", L"A&ttempt GSSAPI authentication (SSH-2 only)" },
	{ "A&llow GSSAPI credential delegation", L"A&llow GSSAPI credential delegation" },
	{ "&Preference order for GSSAPI libraries:", L"&Preference order for GSSAPI libraries:" },
	{ "&Up", L"&Up" },
	{ "&Down", L"&Down" },
	{ "User-supplied GSSAPI library path:", L"User-supplied GSSAPI library path:" },
	{ "Bro&wse...", L"Bro&wse..." },
	{ "Options controlling GSSAPI authentication", L"Options controlling GSSAPI authentication" },
	{ "Don't allocate a &pseudo-terminal", L"Don't allocate a &pseudo-terminal" },
	{ "Terminal modes to send:", L"Terminal modes to send:" },
	{ "&Remove", L"&Remove" },
	{ "&Mode:", L"&Mode:" },
	{ "Value:", L"Value:" },
	{ "Auto", L"Auto" },
	{ "This:", L"This:" },
	{ "A&dd", L"A&dd" },
	{ "Terminal modes", L"Terminal modes" },
	{ "Remote terminal settings", L"Remote terminal settings" },
	{ "&Enable X11 forwarding", L"&Enable X11 forwarding" },
	{ "&X display location", L"&X display location" },
	{ "Remote X11 a&uthentication protocol", L"Remote X11 a&uthentication protocol" },
	{ "MIT-Magic-Cookie-1", L"MIT-Magic-Cookie-1" },
	{ "XDM-Authorization-1", L"XDM-Authorization-1" },
	{ "X au&thority file for local display", L"X au&thority file for local display" },
	{ "Bro&wse...", L"Bro&wse..." },
	{ "X11 forwarding", L"X11 forwarding" },
	{ "Options controlling SSH X11 forwarding", L"Options controlling SSH X11 forwarding" },
	{ "Local por&ts accept connections from other hosts", L"Local por&ts accept connections from other hosts" },
	{ "Remote &ports do the same (SSH-2 only)", L"Remote &ports do the same (SSH-2 only)" },
	{ "Forwarded ports:", L"Forwarded ports:" },
	{ "&Remove", L"&Remove" },
	{ "Add new forwarded port:", L"Add new forwarded port:" },
	{ "&Source port", L"&Source port" },
	{ "Dest&ination", L"Dest&ination" },
	{ "&Local", L"&Local" },
	{ "Re&mote", L"Re&mote" },
	{ "D&ynamic", L"D&ynamic" },
	{ "A&uto", L"A&uto" },
	{ "IPv&4", L"IPv&4" },
	{ "IPv&6", L"IPv&6" },
	{ "A&dd", L"A&dd" },
	{ "Port forwarding", L"Port forwarding" },
	{ "Options controlling SSH port forwarding", L"Options controlling SSH port forwarding" },
	{ "Chokes on SSH-1 &ignore messages", L"Chokes on SSH-1 &ignore messages" },
	{ "Refu&ses all SSH-1 password camouflage", L"Refu&ses all SSH-1 password camouflage" },
	{ "Chokes on SSH-1 &RSA authentication", L"Chokes on SSH-1 &RSA authentication" },
	{ "Chokes on SSH-&2 ignore messages", L"Chokes on SSH-&2 ignore messages" },
	{ "Chokes on PuTTY's SSH-2 'winad&j' requests", L"Chokes on PuTTY's SSH-2 'winad&j' requests" },
	{ "&Miscomputes SSH-2 HMAC keys", L"&Miscomputes SSH-2 HMAC keys" },
	{ "Miscomput&es SSH-2 encryption keys", L"Miscomput&es SSH-2 encryption keys" },
	{ "Detection of known bugs in SSH servers", L"Detection of known bugs in SSH servers" },
	{ "Workarounds for SSH server bugs", L"Workarounds for SSH server bugs" },
	{ "Requires &padding on SSH-2 RSA signatures", L"Requires &padding on SSH-2 RSA signatures" },
	{ "Misuses the sessio&n ID in SSH-2 PK auth", L"Misuses the sessio&n ID in SSH-2 PK auth" },
	{ "Handles SSH-2 &key re-exchange badly", L"Handles SSH-2 &key re-exchange badly" },
	{ "Ignores SSH-2 ma&ximum packet size", L"Ignores SSH-2 ma&ximum packet size" },
	{ "Only supports pre-RFC4419 SSH-2 &DH GEX", L"Only supports pre-RFC4419 SSH-2 &DH GEX" },
	{ "Replies to re&quests on closed channels", L"Replies to re&quests on closed channels" },
	{ "Detection of known bugs in SSH servers", L"Detection of known bugs in SSH servers" },
	{ "Further workarounds for SSH server bugs", L"Further workarounds for SSH server bugs" },
	{ "Seria&l line to connect to", L"Seria&l line to connect to" },
	{ "Select a serial line", L"Select a serial line" },
	{ "&Speed (baud)", L"&Speed (baud)" },
	{ "Data &bits", L"Data &bits" },
	{ "S&top bits", L"S&top bits" },
	{ "&Parity", L"&Parity" },
	{ "&Flow control", L"&Flow control" },
	{ "Configure the serial line", L"Configure the serial line" },
	{ "Options controlling local serial lines", L"Options controlling local serial lines" },
	{ "Auto&detect Cygwin installation", L"Auto&detect Cygwin installation" },
	{ "&Use Cygwin64", L"&Use Cygwin64" },
	{ "Configure Cygwin paths", L"Configure Cygwin paths" },
	{ "Options controlling Cygterm sessions", L"Options controlling Cygterm sessions" },

};

const wchar_t* get_localization_text(const char* text)
{
	if (text == NULL)
	{
		return 0;
	}

	if (conf_get_int(conf, CONF_localization_ui) == 0)
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

	OutputDebugStringA(text);
	OutputDebugStringA("\r\n");
	return 0;
}

HWND WINAPI CreateWindowExAL(_In_ DWORD dwExStyle,
	_In_opt_ LPCSTR lpClassName,
	_In_opt_ LPCSTR lpWindowName,
	_In_ DWORD dwStyle,
	_In_ int X,
	_In_ int Y,
	_In_ int nWidth,
	_In_ int nHeight,
	_In_opt_ HWND hWndParent,
	_In_opt_ HMENU hMenu,
	_In_opt_ HINSTANCE hInstance,
	_In_opt_ LPVOID lpParam)
{
	wchar_t* localization = get_localization_text(lpWindowName);

	if (localization != NULL)
	{
		wchar_t* className = NULL;

		if (lpClassName != NULL)
		{
			className = short_mb_to_wc(CP_ACP, 0, lpClassName, strlen(lpClassName));
		}
		HWND ret = CreateWindowExW(dwExStyle, className, localization, dwStyle, X, Y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam);

		sfree(className);
		return ret;
	}
	else
	{
		return CreateWindowExA(dwExStyle, lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam);
	}
}

HTREEITEM TreeView_InsertItemAL(HWND hwnd, LPTV_INSERTSTRUCTA lpis)
{
	wchar_t* localization = get_localization_text(lpis->itemex.pszText);

	if (localization != NULL)
	{
		TVINSERTSTRUCTW ins;

		ins.hParent = lpis->hParent;
		ins.hInsertAfter = lpis->hInsertAfter;
		ins.itemex.cChildren = lpis->itemex.cChildren;
		ins.itemex.cchTextMax = lpis->itemex.cchTextMax;
		ins.itemex.hItem = lpis->itemex.hItem;
		ins.itemex.hwnd = lpis->itemex.hwnd;
		ins.itemex.iExpandedImage = lpis->itemex.iExpandedImage;
		ins.itemex.iImage = lpis->itemex.iImage;
		ins.itemex.iIntegral = lpis->itemex.iIntegral;
		ins.itemex.iReserved = lpis->itemex.iReserved;
		ins.itemex.iSelectedImage = lpis->itemex.iSelectedImage;
		ins.itemex.lParam = lpis->itemex.lParam;
		ins.itemex.mask = lpis->itemex.mask;
		ins.itemex.state = lpis->itemex.state;
		ins.itemex.stateMask = lpis->itemex.stateMask;
		ins.itemex.uStateEx = lpis->itemex.uStateEx;
		ins.itemex.pszText = localization;

		return (HTREEITEM)SNDMSG((hwnd), TVM_INSERTITEMW, 0, (LPARAM)(LPTV_INSERTSTRUCTW)(&ins));
	}
	else
	{
		return (HTREEITEM)SNDMSG((hwnd), TVM_INSERTITEMA, 0, (LPARAM)(LPTV_INSERTSTRUCTA)(lpis));
	}
}

BOOL WINAPI TextOutAL(_In_ HDC hdc, _In_ int x, _In_ int y, _In_reads_(c) LPCSTR lpString, _In_ int c)
{
	wchar_t* localization = get_localization_text(lpString);

	if (localization != NULL)
	{
		return TextOutW(hdc, x, y, localization, wcslen(localization));
	}
	else
	{
		return TextOutA(hdc, x, y, lpString, c);
	}
}

BOOL WINAPI SetDlgItemTextAL(_In_ HWND hDlg, _In_ int nIDDlgItem, _In_ LPCSTR lpString)
{
	wchar_t* localization = get_localization_text(lpString);

	if (localization != NULL)
	{
		return SetDlgItemTextW(hDlg, nIDDlgItem, localization);
	}
	else
	{
		return SetDlgItemTextA(hDlg, nIDDlgItem, lpString);
	}
}