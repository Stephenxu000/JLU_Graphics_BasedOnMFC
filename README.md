# JLU_Graphics_BasedOnMFC
吉林大学基于MFC实践的图形学课程学习
## 1.前言碎碎念
此项目是在课程一开始就设立，主要是想继续学习一下git的版本控制等知识。<br>
### 1.1 编写README.md文件的格式
/#的个数表示几级标题，等于号=大标题和减号-中标题。补空行可以单独输出线。

------------------------------------------
        单行文本
    
        多行文本
        123
        此处只是简单使用一下，更多编写格式在别的文章里详细写明。
### 1.2 大文件以及.gitignore的忽略规则
push的时候发现上传失败，提示是有文件>100MB<br>
先根据提示想到了使用git lfs<br>
后来发现.vs是VS的编译文件，无需上传，所以此处应该编写忽略规则。<br>
## 2.课程内容
### 2.1 基本功能：<br>
        2.1.1 绘制矩形


        2.1.2 绘制圆形


        2.1.3 设置颜色：
                显示对话框，设置绘制颜色。


        2.1.4 绘制多边形绘制多边形：
                选择此菜单项后，左键鼠标输入顶点绘制多边形。
                实现边标志算法对多边形进行学号后四位填充。


        2.1.5 设置颜色设置颜色：
               选择此菜单项后，显示对话框，在对话框中设置绘制多边形中填充颜色、边界颜色。默认黑色。


        2.1.6 绘制立方体：
                建立立方体的数据模型，采用透视投影。
                6个面可设置颜色然后进行填充。


        2.1.7 延x轴方向平移：
                选择菜单项后，通过键盘按键“A”和“L”分别使立方体延x轴正方向和负方向做指定步长的平移。


        2.1.8 延y轴方向平移：
                选择菜单项后，通过键盘按键“A”和“L”分别使立方体延y轴正方向和负方向做指定步长的平移。


        2.1.9 延z轴方向平移：
                选择菜单项后，通过键盘按键“A”和“L”分别使立方体延z轴正方向和负方向做指定步长的平移。


        2.1.10 绕x轴旋转：
                选择菜单项后，通过键盘按键“A”和“L”分别使立方体绕x轴做指定角度数的正向和反向旋转。


        2.1.11 绕y轴旋转：
                选择菜单项后，通过键盘按键“A”和“L”分别使立方体绕y轴做指定角度数的正向和反向旋转。


        2.1.12 绕z轴旋转：
                选择菜单项后，通过键盘按键“A”和“L”分别使立方体绕 z轴做指定角度数的正向和反向旋转。


        2.1.13 设置数据：
                选择菜单项后，设置功能3.7至3.9的平移步长，默认步长1、设置功能3.10至3.12的每次旋转角度，默认角度为10度；


        2.1.14 绘制Bezier曲线：
                选择此菜单项后，用鼠标左键单击的方式顺序输入控点，控制点数量为4时，绘制以鼠标输入的点为控制点的3次Bezier曲线。
                并且绘制控制多边形，并标记控制点的位置。（以控制点为中心边长为5的矩形）


### 2.2 附加要求：
        2.2.1 
        应用程序中除应用程序中除SetPixel绘图函数以外，
        不使用其他绘图函数；


        2.2.2 
        同组功能（功能所处的二级菜单相同）所绘制的图形要能够同时在视图区存在 
        ，不同组功能在调用前先清屏 （清屏功能可设置成主动调用


        2.2.3 
        用于绘制图形的功能在绘制图形时应实现橡皮线功能，即可实时看到绘制效果（ 
        针对功能 2.1.1、2.1.2、2.1.4、2.1.14 对于2.1.14是实时看到控制多边形）；


        2.2.4 
        实现视图重画功能,即在窗口发生变化需要重新绘制时,视图区中绘制的图形应该仍
        然存在。

------------------------------
## 3.更新日志
### 2020/11/9 
        1.实现了橡皮线功能
                通过语句：dc.SetROP2(R2_MERGEPENNOT);
                设置绘图模式，以屏幕颜色的相反色绘图并上画笔
                问题：擦一次后会重新画一次 延迟很大。
    
        2.实现了DDAline等函数替代MFC给的集成函数（用最基础的SetPixel）
                问题：椭圆函数的右下点对应不上鼠标的拖动点。
                问题原因：在拖动的矩形范围里画了一个相切的圆，而不是鼠标按下点在圆上。
                
        3.实现了基本图形设置颜色功能
    
        4.实现了多边形以及多边形填充（用学号后四位填充）算法
    
        5.实现了多边形边框颜色以及填充颜色的设置。

### 2020/11/15
        1.优化了橡皮线功能
                更改模式：dc.SetROP2(R2_NOTXORPEN);
                设置画笔颜色后 能显示颜色，而没有延迟。
        2.优化了多边形
                原先鼠标点下就连接了，无法预览线段。
                现在点下后拖动能看见橡皮线，鼠标抬起确定线段，
                原先鼠标左键双击结束多边形绘制，但是左键双击必定包含了左键单击。
                现在改成了右键单击结束多边形绘制。
        3.实现了绘制Bezier曲线
                包括控制点的小方块和控制多边形的绘制。
                绘制Bezier曲线使用了MFC的PolyBezier函数。
### 2021/1/3
		1.图形学课程已结课，期末考试结束，故把本项目更新完整，此为最终提交版本。
		2.添加了绘制立方体、填充立方体、立方体图形变换等功能。
		3.实现了部分图像重画功能。（有待进一步完善，目前我只写了直线、元、正方体的图元类）
			原理思路：编写图元类，保存绘制在画布上所有图像的种类（直线、圆、正方体、多边形……）、位置、颜色等基本信息于链表中，每次调用ondraw中，代码如下：

```
for (int i = 0; i < pDoc->m_MapList.GetSize(); i++)
{
	//获得图元列表中的图元子类指针并将其造型成图元基类指针
	CMapElement* pMap = (CMapElement*)pDoc->m_MapList.GetAt(i);
	//调用draw函数绘制图元
	pMap->draw(pDC);
}
```




## 4.效果展示

### 4.1 基本图元绘制
 <div align=center>
 <img src="https://github.com/Stephenxu000/JLU_Graphics_BasedOnMFC/blob/master/Picture/%E5%9F%BA%E6%9C%AC%E5%9B%BE%E5%85%83%E7%BB%98%E5%88%B6.png" alt="基本图元绘制" width="300" height="300" />
 </div>

 ### 4.2 多边形学号填充
 <div align=center>
 <img src="https://github.com/Stephenxu000/JLU_Graphics_BasedOnMFC/blob/master/Picture/%E5%A4%9A%E8%BE%B9%E5%BD%A2%E9%A2%9C%E8%89%B2%E8%AE%BE%E7%BD%AE.png" alt="多边形填充设置" width="300" height="300" />
 </div>

 <div align=center>
 <img src="https://github.com/Stephenxu000/JLU_Graphics_BasedOnMFC/blob/master/Picture/%E5%A4%9A%E8%BE%B9%E5%BD%A2%E5%A1%AB%E5%85%85.png" alt="填充多边形" width="300" height="300" />
 </div>

### 4.3 立方体
 <div align=center>
 <img src="https://github.com/Stephenxu000/JLU_Graphics_BasedOnMFC/blob/master/Picture/%E7%AB%8B%E6%96%B9%E4%BD%93%E5%B1%9E%E6%80%A7%E8%AE%BE%E7%BD%AE.png" alt="立方体属性设置" width="300" height="300" />
 </div>

 <div align=center>
 <img src="https://github.com/Stephenxu000/JLU_Graphics_BasedOnMFC/blob/master/Picture/%E9%80%8F%E8%A7%86%E7%AB%8B%E6%96%B9%E4%BD%93.png" alt="透视立方体" width="300" height="300" />
 </div>

 <div align=center>
 <img src="https://github.com/Stephenxu000/JLU_Graphics_BasedOnMFC/blob/master/Picture/%E5%A1%AB%E5%85%85%E7%AB%8B%E6%96%B9%E4%BD%93.png" alt="填充立方体" width="300" height="300" />
 </div>

 ### 4.4 bezier曲线
 <div align=center>
 <img src="https://github.com/Stephenxu000/JLU_Graphics_BasedOnMFC/blob/master/Picture/bezier%E6%9B%B2%E7%BA%BF.png" alt="bezier曲线" width="300" height="300" />
 </div>