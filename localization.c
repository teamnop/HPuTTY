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
	{ "", L"" },
	{ "Cate&gory:", L"분류(&G):" },
	{ "&Open", L"접속(&O)" },
	{ "&Apply", L"적용(&A)" },
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
	{ "Telnet", L"텔넷" },
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
	{ "(Log file name can contain &&Y, &&M, &&D for date, &&T for\ntime, &&H for host name, and &&P for port number)", L"(로그 파일 이름은 날짜로 &&Y, &&M, &&D를 가질 수 있으며 \n시간으로 &&T 을 가질 수 있고, 호스트명으로 &&H, 포트 번호로 &&P를 가질 수 있습니다. )" },
	{ "What to do if th&e log file already exists:", L"이미 존재하는 파일명일 경우:(&e) " },
	{ "Always overwrite it", L"항상 덮어쓰기" },
	{ "Always append to the end of it", L"파일 끝에 이어서 쓰기" },
	{ "Ask the user every time", L"항상 물어보기" },
	{ "Fl&ush log file frequently", L"주기적으로 로그 파일에 플러시(&u) " },
	{ "Omit &known password fields", L"알고 있는 암호 필드 출력(&k)" },
	{ "Omit session &data", L"세션 데이타 출력(&d)" },
	{ "Options specific to SSH packet logging", L"SSH 패킷을 로깅할 때의 옵션" },
	{ "Options controlling session logging", L"세션 로깅 시의 옵션" },
	{ "Auto &wrap mode initially on", L"자동 개행 모드 초기 활성화(&w)" },
	{ "&DEC Origin Mode initially on", L"&DEC 위치 모드 초기 활성화(&D)" },
	{ "Implicit C&R in every LF", L"모든 LF문자에 암묵적으로 CR문자 추가(&R)" },
	{ "Implicit L&F in every CR", L"모든 CR문자에 암묵적으로 LF문자 추가(&F)" },
	{ "Us&e background colour to erase screen", L"배경색을 이용해 화면 지우기" },
	{ "E&nable blinking text", L"깜박이는 문자 활성화(&n)" },
	{ "An&swerback to ^E:", L"^E 문자 수신에 대한 응답 문자열(&s)" },
	{ "Set various terminal options", L"다양한 터미널 옵션" },
	{ "&Local echo:", L"입력 문자 보이기(&L)" },
	{ "Auto", L"자동 결정" },
	{ "Force on", L"강제로 켜기" },
	{ "Force off", L"강제로 끄기" },
	{ "Local line edi&ting:", L"라인 입력 단위 서버 전송" },
	{ "Auto", L"자동" },
	{ "Force on", L"강제로 켜기" },
	{ "Force off", L"강제로 끄기" },
	{ "Line discipline options", L"입력 처리 옵션" },
	{ "&Printer to send ANSI printer output to:", L"선택할 ANSI 인쇄 가능한 프린터:(&P)" },
	{ "Remote-controlled printing", L"원격 제어하에 인쇄" },
	{ "Options controlling the terminal emulation", L"터미널을 에뮬레이션을 제어하는 옵션" },
	{ "The &Backspace key", L"백 스페이스 키(&B)" },
	{ "Control-H", L"Control-H" },
	{ "Control-? (127)", L"Control-? (127)" },
	{ "Th&e Home and End keys", L"Home 키와 End 키(&e)" },
	{ "Standard", L"표준" },
	{ "rxvt", L"rxvt" },
	{ "The &Function keys and keypad", L"펑션 키와 키패드(&F)" },
	{ "ESC[n~", L"ESC[n~" },
	{ "Linux", L"Linux" },
	{ "Xterm R6", L"Xterm R6" },
	{ "VT400", L"VT400" },
	{ "VT100+", L"VT100+" },
	{ "SCO", L"SCO" },
	{ "4690", L"4690" },
	{ "Change the sequences sent by:", L"다음의 키로 생성되는 코드 변경:" },
	{ "Initial state of cu&rsor keys:", L"방향 키 초기 상태:(&r)" },
	{ "Normal", L"기본" },
	{ "Application", L"어플리케이션" },
	{ "I&nitial state of numeric keypad:", L"숫자 키패드 초기 상태(&n)" },
	{ "Normal", L"기본" },
	{ "Application", L"어플리케이션" },
	{ "NetHack", L"넷핵" },
	{ "Application keypad settings:", L"어플리케이션 키패드 설정" },
	{ "Al&tGr acts as Compose key", L"Al&tGr가 조합 키로 동작" },
	{ "Control-Alt is &different from AltGr", L"Control-Alt가 AltGr와 다르게 동작(&d)" },
	{ "Right-A&lt acts as it is", L"오른쪽 Alt가 원래대로 동작(&l)" },
	{ "Set &meta bit on alt (instead of escape)", L"Alt 시 메타 비트 설정(escape 대신에)(&m)" },
	{ "Enable extra keyboard features:", L"특별한 키보드 기능 활성화:" },
	{ "Options controlling the effects of keys", L"키보드 기능을 바꾸는 옵션" },
	{ "Action to happen when a &bell occurs:", L"벨 이벤트가 발생할 때 취할 동작:(&b)" },
	{ "None (bell disabled)", L"아무것도 하지 않음" },
	{ "Make default system alert sound", L"기본 시스템 알람 사운드 출력" },
	{ "Visual bell (flash window)", L"시각적인 벨 효과(반짝이는 윈도우)" },
	{ "Beep using the PC speaker", L"PC 스피커를 이용한 비프음" },
	{ "Play a custom sound file", L"별도의 사운드 파일 재생" },
	{ "Custom sound file to play as a bell:", L"벨 이벤트시 재생할 사운드 파일:" },
	{ "Bro&wse...", L"찾아보기:(&w)" },
	{ "Taskbar/capt&ion indication on bell:", L"벨 이벤트시 작업 표시줄 표시" },
	{ "Disabled", L"비활성화" },
	{ "Flashing", L"반짝이기" },
	{ "Steady", L"정적 알림" },
	{ "Set the style of bell", L"벨 이벤트의 스타일 설정" },
	{ "Bell is temporarily &disabled when over-used", L"지나친 벨 이벤트 발생 시 비 활성화(&d)" },
	{ "Over-use &means this many bells...", L"지나친 벨 이벤트란 이만큼의:(&m)" },
	{ "... in &this many seconds", L"벨이 이만큼의 시간(초) 안에 발생한다는 의미:(&t)" },
	{ "The bell is re-enabled after a few seconds of silence.", L"수 초간 벨이 조용해진 후에 다시 발생시킬 " },
	{ "&Seconds of silence required", L"시간(초) : (&s)" },
	{ "Control the bell overload behaviour", L"지나친 벨 이벤트 제어" },
	{ "Options controlling the terminal bell", L"터미널의 벨 이벤트 제어 옵션" },
	{ "Disable application c&ursor keys mode", L"어플리케이션 방향 키 모드 비활성화(&u)" },
	{ "Disable application &keypad mode", L"어플리케이션 키 패드 모드 비활성화(&k)" },
	{ "Disable &xterm-style mouse reporting", L"xterm-스타일의 마우스 사용 비활성화(&x)" },
	{ "Di&sable remote-controlled terminal resizing", L"원격 제어된 터미널 크기 조정 비활성화(&s)" },
	{ "Disable s&witching to alternate terminal screen", L"다른 터미널 화면으로의 전환 비활성화(&w)" },
	{ "Disable remo&te-controlled window title changing", L"원격 제어된 윈도우 이름 변경 비활성화(&t)" },
	{ "Response to remote title &query (SECURITY):", L"원격 윈도우 이름 질의에 대한 응답(보안):" },
	{ "None", L"무응답" },
	{ "Empty string", L"빈 문자열" },
	{ "Window title", L"윈도우 제목" },
	{ "Disa&ble destructive backspace on server sending ^?", L"서버가 보내는 ^? 문자열로 인한 문자 삭제 비활성화(&b)" },
	{ "Disable &remote-controlled character set configuration", L"원격 제어된 문자 셋 설정 비활성화(&r)" },
	{ "Disab&le Arabic text shaping", L"아랍 텍스트 모양 비활성화" },
	{ "&Disable bidirectional text display", L"양방향 텍스트 디스플레이 비활성화(아랍권)(&l)" },
	{ "Enabling and disabling advanced terminal features", L"고급 터미널 기능 활성화/비활성화" },
	{ "Colu&mns", L"열(&m)" },
	{ "&Rows", L"행(&r)" },
	{ "When window is resi&zed:", L"윈도우 크기가 재조정 됐을 때(&z)" },
	{ "Change the number of rows and columns", L"열과 행 길이 바꾸기" },
	{ "Change rows and columns only when maximised", L"최대화 됐을 때만 행과 열 바꾸기" },
	{ "Change the size of the font", L"폰트 크기 바꾸기 " },
	{ "Change font size only when maximised", L"최대화 됐을 때만 폰트 크기 바꾸기" },
	{ "Forbid resizing completely", L"크기 재조정 금지" },
	{ "Set the size of the window", L"윈도우 사이즈 설정" },
	{ "Line&s of scrollback", L"스크롤 최대 길이(&s)" },
	{ "Scro&llback lines at a time (-1 half, -2 full screen)", L"한번에 스크롤할 길이(-1 반, -2 풀스크린) (&l)" },
	{ "&Display scrollbar", L"스크롤 바 표시(&D)" },
	{ "D&isplay scrollbar in full screen mode", L"전체 화면 모드에서 스크롤 보이기(&i)" },
	{ "Reset scrollbac&k on keypress", L"키 입력시 스크롤 초기화(&k)" },
	{ "Reset scrollback on dis&play activity", L"출력 있을시 스크롤 초기화(&p)" },
	{ "Push &erased text into scrollback", L"Push &erased text into scrollback" },
	{ "Control the scrollback in the window", L"Control the scrollback in the window" },
	{ "Options controlling PuTTY's window", L"Options controlling PuTTY's window" },
	{ "Cursor appearance:", L"커서 모양새:" },
	{ "B&lock", L"블록(&L)" },
	{ "&Underline", L"밑줄(&U)" },
	{ "&Vertical line", L"수직선(&V)" },
	{ "Cursor &blinks", L"커서 깜박임(&B)" },
	{ "Adjust the use of the cursor", L"커서의 사용을 조정" },
	{ "Fo&nt used in the terminal window", L"터미널 글꼴 선택(&N)" },
	{ "Change...", L"변경..." },
	{ "Use separated unicode &font", L"유니코드는 별도의 글꼴 사용(&F)" },
	{ "Font for unicode characters", L"유니코드용 글꼴" },
	{ "Change...", L"변경..." },
	{ "Adjustment of unicode font (px)", L"유니코드 폰트 조정" },
	{ "Allow selection of variable-pitch fonts", L"Allow selection of variable-pitch fonts" },
	{ "Font &quality:", L"글꼴 품질:" },
	{ "Antialiased", L"Antialiased" },
	{ "Non-Antialiased", L"Non-Antialiased" },
	{ "ClearType", L"ClearType" },
	{ "Default", L"기본" },
	{ "Font settings", L"글꼴 설정" },
	{ "Hide mouse &pointer when typing in window", L"입력할 때 마우스 포인터 숨기기(&P)" },
	{ "Adjust the use of the mouse pointer", L"마우스 포인터" },
	{ "Gap b&etween text and window edge:", L"텍스트와 창 테두리 사이의 간격(&E)" },
	{ "&Sunken-edge border (slightly thicker)", L"가라 앉은 듯한 효과의 테두리 (약간 두껍게)(&S)" },
	{ "Adjust the window border", L"창 테두리" },
	{ "Configure the appearance of PuTTY's window", L"PuTTY 모양새 옵션" },
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
	{ "(Codepages supported by Windows but not listed here,\nsuch as CP866 on many systems, can be entered\nmanually)", L"(Codepages supported by Windows but not listed here,\nsuch as CP866 on many systems, can be entered\nmanually)" },
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
	{ "Select a colour from the list, and then click the Modify\nbutton to change its appearance.", L"Select a colour from the list, and then click the Modify\nbutton to change its appearance." },
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
	{ "Attempt \"keyboard-&interactive\" auth (SSH-2)", L"Attempt \"keyboard-&interactive\" auth (SSH-2)" },
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
	{ "&Flow control", L"흐름 설정(&F)" },
	{ "Configure the serial line", L"Configure the serial line" },
	{ "Options controlling local serial lines", L"Options controlling local serial lines" },
	{ "Auto&detect Cygwin installation", L"Cygwin 자동 탐지(&D)" },
	{ "&Use Cygwin64", L"Cygwin64 사용(&U)" },
	{ "Configure Cygwin paths", L"Cygwin 경로 설정" },
	{ "Options controlling Cygterm sessions", L"Cygterm 세션 설정" },
	{ "&Event Log", L"이벤트 로그(&E)" },
	{ "Ne&w Session...", L"새로운 세션(&W)" },
	{ "&Duplicate Session", L"세션 복제(&D)" },
	{ "Sa&ved Sessions", L"세션 저장(&V)" },
	{ "Chan&ge Settings...", L"설정 변경...(&G)" },
	{ "&Unicode Mode", L"유니코드 모드(&U)" },
	{ "C&opy All to Clipboard", L"클립보드로 모두 복사(&O)" },
	{ "C&lear Scrollback", L"스크롤백 초기화(&L)" },
	{ "Rese&t Terminal", L"터미널 초기화(&T)" },
	{ "&Full Screen", L"전체화면(&F)" },
	{ "&Urls", L"&Urls" },
	{ "Next &Window\tCtrl + Tab", L"다음 창(&W)\tCtrl+Tab" }
};

const wchar_t* get_localization_text(const char* text)
{
	if (text == NULL)
	{
		return 0;
	}

	if (conf == NULL || conf_get_int(conf, CONF_localization_ui) == 0)
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

BOOL APIENTRY GetTextExtentPoint32AL(_In_ HDC hdc, _In_reads_(c) LPCSTR lpString, _In_ int c, _Out_ LPSIZE psizl)
{
	wchar_t* localization = get_localization_text(lpString);

	if (localization != NULL)
	{
		return GetTextExtentPoint32W(hdc, localization, wcslen(localization), psizl);
	}
	else
	{
		return GetTextExtentPoint32A(hdc, lpString, c, psizl);
	}
}

BOOL WINAPI AppendMenuAL(_In_ HMENU hMenu, _In_ UINT uFlags, _In_ UINT_PTR uIDNewItem, _In_opt_ LPCSTR lpNewItem)
{
	wchar_t* localization = get_localization_text(lpNewItem);

	if (localization != NULL)
	{
		return AppendMenuW(hMenu, uFlags, uIDNewItem, localization);
	}
	else
	{
		return AppendMenuA(hMenu, uFlags, uIDNewItem, lpNewItem);
	}
}