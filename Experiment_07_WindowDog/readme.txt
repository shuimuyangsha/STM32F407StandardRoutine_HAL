实验器材:
	阿波罗STM32F429开发板
	
实验目的:
	学习窗口看门狗的使用
	
硬件资源:
	1,DS0(连接在PB1),DS1(连接在PB0) 
	2,窗口看门狗(WWDG)
	3,KEY_UP按键(连接在PA0,也称之为WK_UP)
	
	
实验现象:
	本实验, 程序一运行则开启WWDG,并使得DS0亮300ms后关闭，进入死循环。等待WWDG中断的
	到来，在中断里面，喂狗，并执行DS1的翻转操作。所以可以看到DS1不停的闪烁，而DS0只在
	刚启动的时候闪一下。
	
注意事项:
	无. 
	 
参考资料：阿波罗STM32F429开发指南-库函数版本.pdf 第十一章


-------------------------------------------------------------------------------------------


◆其他重要连接：
  开发板光盘资料下载地址（视频+文档+源码等）：http://www.openedv.com/posts/list/13912.htm


◆友情提示：如果您想以后及时免费的收到正点原子所有开发板资料更新增加通知，请关注微信公众平台：
 2种添加方法：（动动手提升您的学习效率，惊喜不断哦）
（1）打开微信->添加朋友->公众号->输入“正点原子”->点击关注
（2）打开微信->添加朋友->输入“alientek_stm32"->点击关注
 具体微信添加方法，请参考帖子：http://www.openedv.com/posts/list/45157.htm
 


						

						淘宝店铺： http://openedv.taobao.com
						           http://eboard.taobao.com
						公司网站：www.alientek.com
						技术论坛：www.openedv.com
                                                微信公众平台：正点原子
						电话：020-38271790
						传真：020-36773971
						广州市星翼电子科技有限公司
						正点原子@ALIENTEK
						     2016-6月