#pragma once
#pragma comment( lib, "..\\AidPlug\\pljd.lib")
//��LIB��Ҫע��һ��,���ڹ�����������->������->����->�����ض���,���� libc.lib . �����������ܱ���ɹ�

#define Pljd extern "C"
Pljd BOOL	WINAPI PLJD_DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved);                   //Ʈ��LIB�ļ���ʼ��,������ǰ�����һ��
Pljd long	WINAPI P_LoadSystem(long �ռ�˿�,long ����ģʽ,char *��������,char *�����ܳ�,char *���ǩ��,char *���������,long ʱ��Ч��);//Ʈ��ͻ��˳�ʼ��
Pljd char*	WINAPI P_GetLoginIn();													                        //Ʈ��ȡ�ı�����ֵ
Pljd long	WINAPI P_UserLogin(char* �û���,char* ����);								                    //Ʈ��ͻ����û���½
Pljd long	WINAPI P_UserTrialLogin();													                    //Ʈ��ͻ������õ�½
Pljd long	WINAPI P_IsLogin();													                            //Ʈ���ж��û��Ƿ��Ѿ���½
Pljd char*	WINAPI P_UserReg(char* �û���,char* ����,char* ��ֵ����,char* ��Ϸ��,char* ������);	            //Ʈ���û�ע��,��Ϸ�ſɿ�
Pljd char*	WINAPI P_ChangeBinding(char* �û���,char* ����,char* ��Ϸ��);					                //Ʈ���û�ת��
Pljd char*	WINAPI P_CardReCharge(char* �û���,char* ��ֵ����,char* �ƹ���Ա);			                    //Ʈ���û����ܳ�ֵ
Pljd char*	WINAPI P_OrderReCharge(char* �û���,char* �������,char* ��Ʒ���);			                    //Ʈ���û�������ֵ
Pljd char*	WINAPI P_ChangePwd(char* �û���,char* ԭʼ����,char* ��������);		                            //Ʈ���û��޸�����
Pljd char*	WINAPI P_GetStaticValue(char* �����ܳ�);										                //Ʈ��ͻ���ȡ��̬����
Pljd char*	WINAPI P_GetGameUser();													                        //Ʈ��ͻ���ȡ��Ϸ��
Pljd long	WINAPI P_CheckAgain();													                        //Ʈ�������֤
Pljd char*	WINAPI P_GetInfo(long ����);										                            //Ʈ��ͻ���ȡ�����Ϣ
Pljd char*	WINAPI P_ApiCall(char* ������,char* ����һ,char* ������,char* ������,char* ������,char* ������);//Ʈ��APICALL
Pljd long	WINAPI P_Checktime();													                        //ʱ��Ч��
Pljd long	WINAPI P_Timingbox(char* ��ʾ��Ϣ,long �ȴ�ʱ��);				       	                        //��ʱ��Ϣ��
Pljd long	WINAPI P_IsConnectNet();													                    //Ʈ���Ƿ��뻥��������
Pljd char*	WINAPI P_GetMachine();													                        //Ʈ��ȡ������
Pljd char*	WINAPI P_GetExpireTime(char* �û���);                                                           //Ʈ��ͻ��˲�ѯ����ʱ��


//��������Initialization
//��������Ʈ��ͻ��˳�ʼ��(�ռ�˿�,����ģʽ,��������,�����ܳ�,���ǩ��,���������,ʱ��Ч��)
//������(�ռ�˿�[Integer],����ģʽ[Integer],��������[String],�����ܳ�[String],���ǩ��[String],���������[String],ʱ��Ч��[Integer])