Scripts of building [speex][] and [ogg][] for iOS and OS X.

1.在脚本目录下执行./build_speex.sh
```sh
$ ./build_speex.sh
```
2.若下载失败，手动下载[ogg-source][]和[speex-source][]放到脚本目录下，再次执行脚本

### 报错处理：

找不到符号speex_decode,speex_decode_stereo。需要禁用DISABLE_FLOAT_API宏。
解决方法，speex 源码找到configure.ac文件，搜索DISABLE_FLOAT_API，按照下面代码修改

```sh
AC_ARG_ENABLE(float-api, [  --disable-float-api     Disable the floating-point API],
[if test "$enableval" = yes; then
  AC_DEFINE([DISABLE_FLOAT_API], , [Disable all parts of the API that are using floats])
fi])
```




[speex]: http://www.speex.org/
[ogg]: http://www.xiph.org/ogg/
[ogg-source]:  http://downloads.xiph.org/releases/ogg/libogg-1.3.5.tar.gz
[ speex-source]:  http://downloads.xiph.org/releases/speex/speex-1.2.1.tar.gz
