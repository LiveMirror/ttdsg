#pragma once
#pragma comment( lib, "..\\AidPlug\\pljd.lib")
//此LIB需要注意一点,请在工程属性里面->链接器->输入->忽略特定库,输入 libc.lib . 忽略这个库才能编译成功

#define Pljd extern "C"
Pljd BOOL	WINAPI PLJD_DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved);                   //登陆插件LIB文件初始化,必须在前面调用一次
Pljd long	WINAPI P_LoadSystem(long 空间端口,long 传输模式,char *传输密码,char *独立密匙,char *软件签名,char *定义机器码,long 时钟效验);//登陆插件客户端初始化
Pljd char*	WINAPI P_GetLoginIn();													                        //登陆插件取文本返回值
Pljd long	WINAPI P_UserLogin(char* 用户名,char* 密码);								                    //登陆插件客户端用户登陆
Pljd long	WINAPI P_UserTrialLogin();													                    //登陆插件客户端试用登陆
Pljd long	WINAPI P_IsLogin();													                            //登陆插件判断用户是否已经登陆
Pljd char*	WINAPI P_UserReg(char* 用户名,char* 密码,char* 充值卡密,char* 游戏号,char* 代理商);	            //登陆插件用户注册,游戏号可空
Pljd char*	WINAPI P_ChangeBinding(char* 用户名,char* 密码,char* 游戏号);					                //登陆插件用户转绑
Pljd char*	WINAPI P_CardReCharge(char* 用户名,char* 充值卡密,char* 推广人员);			                    //登陆插件用户卡密充值
Pljd char*	WINAPI P_OrderReCharge(char* 用户名,char* 订单编号,char* 商品编号);			                    //登陆插件用户订单充值
Pljd char*	WINAPI P_ChangePwd(char* 用户名,char* 原始密码,char* 新设密码);		                            //登陆插件用户修改密码
Pljd char*	WINAPI P_GetStaticValue(char* 数据密匙);										                //登陆插件客户端取静态数据
Pljd char*	WINAPI P_GetGameUser();													                        //登陆插件客户端取游戏号
Pljd long	WINAPI P_CheckAgain();													                        //登陆插件二次验证
Pljd char*	WINAPI P_GetInfo(long 类型);										                            //登陆插件客户端取软件信息
Pljd char*	WINAPI P_ApiCall(char* 函数名,char* 参数一,char* 参数二,char* 参数三,char* 参数四,char* 参数五);//登陆插件APICALL
Pljd long	WINAPI P_Checktime();													                        //时间效验
Pljd long	WINAPI P_Timingbox(char* 提示信息,long 等待时间);				       	                        //定时信息框
Pljd long	WINAPI P_IsConnectNet();													                    //登陆插件是否与互联网连接
Pljd char*	WINAPI P_GetMachine();													                        //登陆插件取机器码
Pljd char*	WINAPI P_GetExpireTime(char* 用户名);                                                           //登陆插件客户端查询到期时间


//函数名：Initialization
//中文名：登陆插件客户端初始化(空间端口,传输模式,传输密码,独立密匙,软件签名,定义机器码,时钟效验)
//参数：(空间端口[Integer],传输模式[Integer],传输密码[String],独立密匙[String],软件签名[String],定义机器码[String],时钟效验[Integer])