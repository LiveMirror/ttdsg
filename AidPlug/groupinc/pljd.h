#pragma once
#pragma comment( lib, "..\\AidPlug\\pljd.lib")
//��LIB��Ҫע��һ��,���ڹ�����������->������->����->�����ض���,���� libc.lib . �����������ܱ���ɹ�

#define Pljd extern "C"
Pljd BOOL	WINAPI PLJD_DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved);                   //��½���LIB�ļ���ʼ��,������ǰ�����һ��
Pljd long	WINAPI P_LoadSystem(long �ռ�˿�,long ����ģʽ,char *��������,char *�����ܳ�,char *���ǩ��,char *���������,long ʱ��Ч��);//��½����ͻ��˳�ʼ��
Pljd char*	WINAPI P_GetLoginIn();													                        //��½���ȡ�ı�����ֵ
Pljd long	WINAPI P_UserLogin(char* �û���,char* ����);								                    //��½����ͻ����û���½
Pljd long	WINAPI P_UserTrialLogin();													                    //��½����ͻ������õ�½
Pljd long	WINAPI P_IsLogin();													                            //��½����ж��û��Ƿ��Ѿ���½
Pljd char*	WINAPI P_UserReg(char* �û���,char* ����,char* ��ֵ����,char* ��Ϸ��,char* ������);	            //��½����û�ע��,��Ϸ�ſɿ�
Pljd char*	WINAPI P_ChangeBinding(char* �û���,char* ����,char* ��Ϸ��);					                //��½����û�ת��
Pljd char*	WINAPI P_CardReCharge(char* �û���,char* ��ֵ����,char* �ƹ���Ա);			                    //��½����û����ܳ�ֵ
Pljd char*	WINAPI P_OrderReCharge(char* �û���,char* �������,char* ��Ʒ���);			                    //��½����û�������ֵ
Pljd char*	WINAPI P_ChangePwd(char* �û���,char* ԭʼ����,char* ��������);		                            //��½����û��޸�����
Pljd char*	WINAPI P_GetStaticValue(char* �����ܳ�);										                //��½����ͻ���ȡ��̬����
Pljd char*	WINAPI P_GetGameUser();													                        //��½����ͻ���ȡ��Ϸ��
Pljd long	WINAPI P_CheckAgain();													                        //��½���������֤
Pljd char*	WINAPI P_GetInfo(long ����);										                            //��½����ͻ���ȡ�����Ϣ
Pljd char*	WINAPI P_ApiCall(char* ������,char* ����һ,char* ������,char* ������,char* ������,char* ������);//��½���APICALL
Pljd long	WINAPI P_Checktime();													                        //ʱ��Ч��
Pljd long	WINAPI P_Timingbox(char* ��ʾ��Ϣ,long �ȴ�ʱ��);				       	                        //��ʱ��Ϣ��
Pljd long	WINAPI P_IsConnectNet();													                    //��½����Ƿ��뻥��������
Pljd char*	WINAPI P_GetMachine();													                        //��½���ȡ������
Pljd char*	WINAPI P_GetExpireTime(char* �û���);                                                           //��½����ͻ��˲�ѯ����ʱ��


//��������Initialization
//����������½����ͻ��˳�ʼ��(�ռ�˿�,����ģʽ,��������,�����ܳ�,���ǩ��,���������,ʱ��Ч��)
//������(�ռ�˿�[Integer],����ģʽ[Integer],��������[String],�����ܳ�[String],���ǩ��[String],���������[String],ʱ��Ч��[Integer])