ʹ�������ܼ�Ҫ˵��:
1��IO���ƣ����÷�������
1)
TSIOOperation operator_IO;//�������IO�Ľṹ��
TSStandardIOInit(GPIOA,GPIO_Pin_2,GPIO_Mode_Out_OD,GPIO_Speed_2MHz,&operator_IO_1);��ʼ���ṹ��
PS���Ƽ�ʹ��GPIO_Mode_Out_OD����������(�����)���Ը��Ӹ�Ч�ʵ�ʹ�ÿ��

2.1)���:operator_IO.High(&operator_IO.struct_GPIO)  
	 operator_IO.Low(&operator_IO.struct_GPIO)
2.2)����:operator_IO_1.ReadBit(&operator_IO_1.struct_GPIO)  //����һ�ζ�ȡ��Ҫ4.85us��8.83us����(��103c8t6 8Mhz����Ƭ����)



