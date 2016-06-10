# HPuTTY에 기여하기

1. 저장소를 Fork후 Clone 합니다
2. [Visual Studio 2015 Community로 빌드하기](https://github.com/teamnop/HPuTTY/wiki/Visual-Studio-2015-Community-%EB%A1%9C-%EB%B9%8C%EB%93%9C%ED%95%98%EA%B8%B0) 문서를 참고하여 빌드를 합니다.
3. 아래 가이드라인에 따라 코드를 편집합니다.
4. Pull-Request를 보냅니다.

## 코드에 기여하기

HPuTTY는 upstream(PuTTYTray)의 변경점을 지속적으로 반응하는것을 목표로 하는 프로젝트 이기 때문에
아래 몇가지 코딩 가이드를 지켜주시면 좋겠습니다.

1. 가능하면 merge충돌을 피하기 위해 기존 코드를 최소한으로 수정합니다.
2. upstream 함수에 새로운 기능을 추가할때 아래와 같은 주석을 표시합니다. 아래 코드로 추후 merge시에 저희가 수정한 기능을 쉽게 알아 볼 수 있습니다.

````
  /*
   * HACK: HPuTTY 기능 이름
   * 설명
   */
````

