/**
 *@ClassName Instruct
 *@Author brewlin
 *@Date 2020/12/14 0014 下午 4:35
 *@Version 1.0
 **/
#ifndef COLANG_ASMER_INSTRUCT_H
#define COLANG_ASMER_INSTRUCT_H

namespace asmer{

    //modrm字段
    struct ModRM
    {
        int mod;//0-1
        int reg;//2-4
        int rm;//5-7
        ModRM();
        void init();
    };
    //sib字段
    struct SIB
    {
        int scale;//0-1
        int index;//2-4
        int base;//5-7
        SIB();
        void init();
    };
    //指令的其他部分
    struct Inst
    {
        unsigned char opcode;
        int disp;
        int imm32;
        int dispLen;//偏移的长度
        Inst();
        void init();
        //设置disp，自动检测disp长度（符号），即使是无符号地址值也无妨
        void setDisp(int d,int len);
        void writeDisp();
    };

    class Instruct{
    public:
        Instruct(Token type):type(type){}
        ~Instruct(){}

        Token  type;
        Inst*  inst;
        SIB*   sib;
        ModRM* modrm;
    };

};

#endif //COLANG_INSTRUCT_H
