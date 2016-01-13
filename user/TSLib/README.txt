使用这个框架简要说明:
1、IO控制，调用方法步骤
1)
TSIOOperation operator_IO;//定义操作IO的结构体
TSStandardIOInit(GPIOA,GPIO_Pin_2,GPIO_Mode_Out_OD,GPIO_Speed_2MHz,&operator_IO_1);初始化结构体
PS：推荐使用GPIO_Mode_Out_OD加上拉电阻(必须接)可以更加高效率地使用框架

2.1)输出:operator_IO.High(&operator_IO.struct_GPIO)  
	 operator_IO.Low(&operator_IO.struct_GPIO)
2.2)输入:operator_IO_1.ReadBit(&operator_IO_1.struct_GPIO)  //正常一次读取需要4.85us到8.83us左右(在103c8t6 8Mhz晶振单片机上)



