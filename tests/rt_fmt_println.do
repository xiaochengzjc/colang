package main

import fmt

func main(){
    a = -1323
    if(a){
        fmt.sprintf("a is negative not should be here %d %s\n",a,"wrong")
    }else{
        fmt.sprintf("ok %d %s\n",a,"it's clear")
    }
}

