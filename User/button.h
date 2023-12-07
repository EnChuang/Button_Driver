#ifndef BUTTON_H
#define BUTTON_H

#include "stdint.h"
#define KEY_ON	0											//���sĲ�o�q��

#define BTN_NAME_MAX  32     //���s�W�ٿ�J�̤j��

/* ���s���u�ɶ�40ms, ��ĳ�եζg����20ms
 �u���s���˴���40ms���A���ܤ~�{�����ġA�]�A�u�_�M���U��بƥ�
*/

#define CONTINUOS_TRIGGER             0  //�O�_����s��Ĳ�o�A�s�o���ܴN���n�˴��������P�����F	


/* ���\��O�_����P�ɦs�b�����M����Ĳ�o�����p�A�Y��ܶ}�ҥ����w�q�A�h�����M�������|Ĳ�o�A
���L�������T���|����A�]���t�λݭn�P�_��������O�_Ĳ�o�F�����A����ɶ����������j�ɶ� BUTTON_DOUBLE_TIME�C
�Y���ҥΥ����w�q�A��ĳ�b�u�{���ȫO�d���������������@�ءA�H�K�b�����T����Ĳ�o�����n�������A�]�������ݭn�b�@�����U�M�����~�|�ͦ��C */
#define SINGLE_AND_DOUBLE_TRIGGER     1

/* �O�_���\�Ȧb�����B�����~Ĳ�o�\��A�Y�ҥΦ������w�q�A�h�Ȧb�Τ�����������~�|Ĳ�o�@���榸�����ƥ�C
�Ϥ��A�Y���ҥΦ��w�q�A�h�b�������w�ɶ���N����Ĳ�o�����ƥ�AĲ�o�g���h�� BUTTON_LONG_CYCLE �ѼƩҨM�w�C */#define LONG_FREE_TRIGGER             0

#define BUTTON_DEBOUNCE_TIME        2   //�����u���ɶ�      (n-1)*�եζg��
#define BUTTON_CONTINUOS_CYCLE     1	  //�s��Ĳ�o�g���ɶ�  (n-1)*�եζg��  
#define BUTTON_LONG_CYCLE          1	  //����Ĳ�o�g���ɶ�  (n-1)*�եζg�� 
#define BUTTON_DOUBLE_TIME         25  //�������j�ɶ�  (n-1)*�եζg��  ��ĳ�b200-600ms
#define BUTTON_LONG_TIME            150  /* ����n��((n-1)*�եζg�� ms)�A�{�������ƥ� */

#define TRIGGER_CB(event)   \
        if(btn->CallBack_Function[event]) \
          btn->CallBack_Function[event]((Button_t*)btn)

typedef void (*Button_CallBack)(void*);   /* ���sĲ�o�^�ը�ơA�ݭn�Τ��{ */



typedef enum {
    BUTTON_DOWM = 0,
    BUTTON_UP,
    BUTTON_DOUBLE,
    BUTTON_LONG,
    BUTTON_LONG_FREE,
    BUTTON_CONTINUOS,
    BUTTON_CONTINUOS_FREE,
    BUTTON_ALL_RIGGER,
    number_of_event, /* Ĳ�o��callback�ƥ� */
    NONE_TRIGGER
} Button_Event;

/*�C�ӫ���ҹ��������c���ܶq�C*/
typedef struct button
{
    uint8_t (*Read_Button_Level)(void); /* Ū������q���ơA�ݭn�Τ�ۤv��{ */

    char Name[BTN_NAME_MAX];

    uint8_t Button_State : 4;										/* �����e���A�]���U�٬O�u�_�^ */
    uint8_t Button_Last_State : 4;						/* �W�@�������䪬�A�A�Ω�P�_���� */
    uint8_t Button_Trigger_Level : 2;				/* ����Ĳ�o�q�� */
    uint8_t Button_Last_Level : 2;						/* �����e�q�� */
    uint8_t Button_Trigger_Event;     			/* ����Ĳ�o�ƥ�A�����A�����A������ */
    Button_CallBack CallBack_Function[number_of_event];
    uint8_t Button_Cycle;	           						/* ����g�� */
    uint8_t Timer_Count;												/* �p�� */
    uint8_t Debounce_Time;										/* �����u���ɶ� */
    uint8_t Long_Time;		 											 /* �����]�w�ɶ� */
    struct button *Next;
} Button_t;

/* �ѥ~���եΪ�����n�� */
void	Button_Inital(void);
void Button_Create(const char *name,Button_t *btn,uint8_t(*read_btn_level)(void),uint8_t btn_trigger_level);
void Button_Attach(Button_t *btn,Button_Event btn_event,Button_CallBack btn_callback);
void Button_Cycle_Process(Button_t *btn);
void Button_Process(void);
uint8_t Get_Button_Event(Button_t *btn);
uint8_t Get_Button_State(Button_t *btn);
void Button_Process_CallBack(void *btn);
void Btn1_Down_CallBack(void *btn);
void Btn1_Double_CallBack(void *btn);
void Btn1_Long_CallBack(void *btn);
void Btn1_Continuos_CallBack(void *btn);
void Btn1_ContinuosFree_CallBack(void *btn);
void Btn2_Down_CallBack(void *btn);
void Btn2_Double_CallBack(void *btn);
void Btn2_Long_CallBack(void *btn);
void Btn2_Continuos_CallBack(void *btn);
void Btn2_ContinuosFree_CallBack(void *btn);

void Get_Button_EventInfo(Button_t *btn);
void Button_Delete(Button_t *btn);
void Search_Button(void);
#endif
