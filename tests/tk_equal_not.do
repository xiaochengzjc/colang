package main

import fmt
import os

#测试 值比较
func test_int_notequal(num){
    fmt.sprintln("test int var not equal...\n")
    if( num != 100){
        fmt.sprintln("test %d != 100 failed...\n",num)
        os.exit(1)
    }else{
        fmt.sprintln("test %d != 100 success...\n",num)
    }
    if( num != 10){
        fmt.sprintln("test %d != 10  success...\n",num)
    }else{
        fmt.sprintln("test %d != 10  failed...\n",num)
        os.exit(1)
    }
}

func test_string_notequal(str){
    fmt.sprintln("test string var not equal...\n")

    if( str != "notequal"){
        fmt.sprintln("test %s != notequal failed...\n",str)
        os.exit(1)
    }else{
        fmt.sprintln("test %s != notequal success...\n",str)
    }

    if( str != 100){
        fmt.sprintln("test %s != 100 success...\n",str)
    }else{
        fmt.sprintln("test %s != 100 success...\n",str)
        os.exit(1)
    }
}

func main(){
    #测试 数字
    test_int_notequal(100)
    #测试字符串
    test_string_notequal("notequal")
}

