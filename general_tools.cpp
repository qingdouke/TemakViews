#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include<QString>
using namespace std;

QString convertToDecimalString(QString numStr,int bit_numb) {
    int num = numStr.toInt();  // 将字符串转化为整数
    double decimalNum = (float)num ;
    for (int i = 0; i < bit_numb; ++i)
    {
        decimalNum = decimalNum / 10.0;
    }
    QString restr = QString::number(decimalNum,'f',bit_numb);

    return restr;  // 将带有两位小数的数字转化为字符串并返回
}
