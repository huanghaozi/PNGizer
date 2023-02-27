# PNGizer
一个能使图片背景半透明化的小工具

下载： [Release](https://github.com/huanghaozi/PNGizer/releases "Release") 

# 概述
之前我写过一篇[“使用Pillow对图片进行滤色”](https://huanghaozi.cn/index.php/2020/04/05/colorfilter/ "“使用Pillow对图片进行滤色”")的文章，不过很多朋友没有Python，而且Python搭环境可能也比较复杂，因此我就用C++将其算法重制成了一个软件...

![](https://cdn.jsdelivr.net/gh/huanghaozi/Storage4App@master/20200804/20200804114954fb1b1526d3c58f792dadba4f19793ed0.jpg)

# 原理重述
![](https://cdn.jsdelivr.net/gh/huanghaozi/ImgHosting@logo/img/colorFilter.jpg)

如上图，就是设置要滤掉的颜色附近n个单位颜色值的**透明度**，这里的n可以调节，对应软件中的**半透明化像素范围**。

黑白图可将这个**n设置到最大值255**，让纯白到纯黑中间的灰色也使用alpha通道调节。

软件达到的效果即为下图中**“理想的效果”**：

![](https://cdn.jsdelivr.net/gh/huanghaozi/ImgHosting/img/pngalpha.jpg)

# 软件下载
- x86为32位版本
- x64为64位版本
- installer为安装包
- green为绿色版压缩包（解包直接点击PNGizer.exe即可使用）

[蓝奏云](https://huanghaozi.lanzous.com/b015o09ch "蓝奏云")：[https://huanghaozi.lanzous.com/b015o09ch](https://huanghaozi.lanzous.com/b015o09ch)

[Github](https://github.com/huanghaozi/PNGizer/releases "Github")：[https://github.com/huanghaozi/PNGizer/releases](https://github.com/huanghaozi/PNGizer/releases)

# 软件源码
[https://github.com/huanghaozi/PNGizer](https://github.com/huanghaozi/PNGizer)
