**Makefileの場合**<br>
configure.make 11行目をopenframeworksのフォルダを指定するようにしてください。 <br>
例) ~~~ /of_v0.11-1.2_osx_release/」
<br>
**IDE(Xcode)の場合**<br>
openframeworksのフォルダがxprojファイルから相対的に「../../../」となる位置へ配置してください。 <br>
例)「($ofのPATH) / apps / myApps / hoge / (xprojココ)」はよい例

