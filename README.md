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
2.1.1 绘制矩形：选择此菜单项后，可利用鼠标在视图区绘制矩形；<br>

2.1.2 绘制圆形：选择此菜单项后，可利用鼠标在视图区绘制圆形；<br>

2.1.3 设置颜色：选择此菜单项后，显示对话框，在此对话框中设置绘制的矩
形和圆形的颜色；<br>

2.1.4 绘制多边形绘制多边形：选择此菜单项后，可通过：选择此菜单项后，可通过鼠标输入顶点的方法绘制多边形，鼠标输入顶点的方法绘制多边形，并实现并实现边标志算法完成对该多边形的填充边标志算法完成对该多边形的填充，要求完成使用自己学号的后四位，要求完成使用自己学号的后四位数字对多边形内部进行填充。<br>

2.1.5 设置颜色设置颜色：选择此菜单项后，显示对话框，在对话框中设置：选择此菜单项后，显示对话框，在对话框中设置2.1.4中所绘制中所绘制多边形中填充的学号的颜色多边形中填充的学号的颜色和边界颜色和边界颜色（默认颜色为黑色）；<br>

2.1.6 绘制立方体：建立立方体的数据模型，选择此菜单项后，将该立方体在视图区中绘制出来，要求采用透视投影6个面的每个面用不同颜色填充，投影结果应正确显示面的可见性的可见性。因为后面的功能2.1.7至2.1.12是对该立方体的变换，所以该菜单项也具有恢复立方体原始数据的效果，即不论后面的变换将立方体变换到哪个位置，都可以通过选择此项功能把立方体恢复到最初位置；<br>

2.1.7 延x轴方向平移：：选择此菜单项后，可以通过键盘按键“ A”和 L”分别使立方体延 x轴正方向和负方向做指定步长的平移 ，每次平移后都要将平移后的 立方体绘制在视图区中 （只保留最新位置的立方体的绘制结果，不能多次变换后，视图区出现多个立方体的投影结果） ），要求使用的投影为透视投影投影中心为 2.1.6中所使用的投影中心；<br>

2.1.8 延y轴方向平移：：选择此菜单项后，可以通过键盘按键 A”和 L”分别使立方体延 y轴正方向和负方向做指定步长的平移，每次平移后都要将平移后的立方体绘制在视图区中 （只保留最新位置的立方体的绘制结果，不能多次变换后，视图区出现多个立方体的投影结果）），要求使用的投影为透视投影投影中心为 2.1.6中所使用的投影中心；<br>

2.1.9 延z轴方向平移：：选择此菜 单项后，可以通过键盘按键“ A”和 L”分别使立方体延 z轴正方向和负方向做指定步长的平移，每次平移后都要将平移后的立方体绘制在视图区中 （只保留最新位置的立方体的绘制结果，不能多次变换后，视图区出现多个立方体的投影结果） ），要求使用的投影为透视投影投影中心为 2.1.6中所使用的投影中心；<br>

2.1.10 绕x轴旋转：：选择此菜单项后，可以通过键盘按键 A”和 L”分别使立方体绕 x轴做指定角度数的正向和反向旋转，每次旋转后都要将旋转后的立方体绘制在视图区中 （只保留最新位置的立方体的绘制结果，不能多次变换后，视图区出现多个立方体的投影结果） ），要求使用的投影为透视投影，投影中心为 2.1.6中所使用的投影中心；<br>

2.1.11 绕y轴旋转：：选择此菜单项后，可以通过键盘按键 A”和 L”分别使立方体绕 y轴做指定角度数的正向和反向旋转，每次旋转后都要将旋转后的立方体绘制在视图区中 （只保留最新位置的立方体的绘制结果，不能多次变换后，视图区出现多个立方体的投影结果） ），要求使用的投影为透视投影，投影中心为 3.6中所使用的投影中心；<br>

2.1.12 绕z轴旋转：：选择此菜单项后，可以通过键盘按键 A”和 L”分别使立方体绕 z轴做指定角度数的正向和反向旋转，每次旋转后都要将旋转后的立方体绘制在视图区中 （只保留最新位置的立方体的绘制结果，不能多次变换后，视图区出现多个立方体的投影结果） ），要求使用的投影为透视投影，投影中心为 2.1.6中所使用的投影中心；<br>

2.1.13 设置数据：：选择此菜单项后，显示对话框，设置功能 3.7至 3.9的平移步长，默认步长为 1，以及设置功能 3.10至 3.12的每次旋转角度，默认角度为 10度；<br>

2.1.14 绘制Bezier曲线：选择此菜单项后，可在视图区用鼠标左键单击的方式顺序输入控点，控制点数量为4时，绘制以鼠标输入的点为控制点的3次Bezier曲线，要求绘制出控制多边形，并标记控制点的位置（以控制点为中心绘制一个小黑色实心矩形，矩形边长为 5）；<br>

### 2.2 附加要求：
2.2.1 应用程序中除应用程序中除SetPixel绘图函数以外，不使用其他绘图函数；<br>

2.2.2 同组功能（功能所处的二级菜单相同）所绘制的图形要能够同时在视图区存在 ，不同组功能在调用前先清屏 （清屏功能可设置成主动调用<br>

2.2.3 用于绘制图形的功能在绘制图形时 应 实现橡皮线功能，即可实时看到绘制效果（ 针对功能 2.1.1、2.1.2、2.1.4、2.1.14 对于2.1.14是实时看到控制多边形）；<br>

2.2.4 实现视图重画功能,即在窗口发生变化需要重新绘制时,视图区中绘制的图形应该仍然存在。<br>
