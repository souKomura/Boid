# Boids***
Boids is an artificial life program which simulates the flocking behaciour of birds.
![スクリーンショット 2021-07-20 21 06 42](https://user-images.githubusercontent.com/87483306/126321004-c6a411a4-6bc2-4667-b6ce-1cab2465ee65.png)

## Requirement
***
* openFrameworks
* make or Xcode
under openFrameworks 0.11.2 is tested

## Usage
***
Please open configure.make and chage **OF_ROOT** path at Line.11.
then, 
```bash
make
make RunRelease
```


**Makefileの場合**<br>
configure.make 11行目をopenframeworksのフォルダを指定するようにしてください。 <br>
例) ~~~ /of_v0.11-1.2_osx_release/」

**IDE(Xcode)の場合**<br>
openframeworksのフォルダがxprojファイルから相対的に「../../../」となる位置へ配置してください。 <br>
例)「($ofのPATH) / apps / myApps / hoge / (xprojココ)」はよい例
***
2-dimention Boid algorithm.<br>
based on Nature of Code chap.06<br>

