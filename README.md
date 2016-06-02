# HPuTTY


[PuTTYTray][1] 기반의 [iPuTTY][2]의 한글 패치를 적용한 PuTTY

## 사용 방법

1. 설치 후 사용

  1. 프로젝트 [Releases](https://github.com/teamnop/HPuTTY/releases/latest) 페이지에서 hputty-*-installer.exe 파일 다운로드
  2. installer 파일 실행 후 설치
  3. 시작 메뉴에서 HPuTTY &gt; putty 항목을 찾아 실행

2. 다운로드 후 사용

  1. 프로젝트 [Releases](https://github.com/teamnop/HPuTTY/releases/latest) 페이지에서 putty.exe 다운로드
  2. putty.exe 실행

## [iPuTTY][2] 에서 가져온 기능

* On-the-spot IME 지원 - IME 조합을 커서에서 직접 조합합니다. IME 조합시 터미널 창을 벗어나서 조합하거나, 커서가 이상 하게 보이는 문제가 해결 됩니다.
* CP949/UTF-8 빠른 변경 메뉴 - 레거시 서버에서 빠르게 인코딩 전환이 가능합니다.
* ANSI/유니코드 폰트 분리 - ANSI 문자와 폰트와, 유니코드 폰트를 따로 지정 가능합니다.
* 투명도 조절 단축키

  * `alt + [, ]` 키를 사용해서 3단계 ( 거의 투명, 약간 투명, 불투명 ) 으로 투명도 조절
  * `alt + shift +[, ]` 키를 사용해서 미세한 투명도 조절
  
* 윈도우 버전을 인식하여 폰트 지정 ( 윈도우 Vista이상에서는 Consolas, XP 이하에서는 Courier New 사용 )
* UTF-8을 기본 인코딩으로 설정

## License

MIT license.

자세한 내용은 `LICENSE` 파일을 참고하세요.

  [1]: https://puttytray.goeswhere.com/
  [2]: https://bitbucket.org/daybreaker/iputty/
