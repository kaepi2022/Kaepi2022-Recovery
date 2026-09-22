#include <stdio.h>
#include <string.h>

const char* yaju_aa[] = {
    "gggmmmmHHHHHHHkkkkkkkkkkkkkkqqqqqqqmggg@@@@@@@HMHH",
    "HNMHY\"=`     ?UHkkqkqkkqkqHHHHHHHmmmmgggHH9U0YYTYM",
    "`  ``   ` `    .THkkkqqHH@MH9UUWMMMMHHHH3?TC_.?1(z",
    "  `  ` ` ` `  `   7WWHMMHUXzvzvvzXHMMHMM@_.`.`...`",
    "`` `  ` `     `. ..JUUXwUHkuzzuzzzXUHMMHNk<_`````.",
    " ``.`..```````.(wwwrrruZXHHkwuzzzzzuXHHMHNs...`.`.",
    "``.`````````.JX0wrOzOwwuXWUUXXXzuuZXZVHMHHN<.`.```",
    "__-`.`.```.JXXzwwwXXXWkwwXWHqkkkZZyyyVWM@HMr..``.`",
    "~~~_-.`...wuXXXkHHHkWXHHpb0XWWWHWWffffbH@HHN+.....",
    "::~~_.. (kuuXkWVMm+THWkHHSrXuuZXWkpfppHHH@H@K_....",
    ";:::__(dqWkXZWHkAWNsXfbSwOzwXXWpffpWHHHHH@@@H<_~..",
    ";::<JdfHgHmHkXVHqkHHfW0wwuZZyyVVffpH@HHHH@HMH>_~..",
    "AuQWWWWH@ggHHbWyffWZuuuXXyyyZyyyfWHMHHHH@HM8I<~...",
    "yyVXZWWHH@@@HHkkyyyyXWfffVVVyyVWHMHHHHHHMB6<<__...",
    "ZyyXXXWpWMHH@@HHHWfffffffVffppHHHMMHHMM6z<~~~.....",
    "ZZZyfpWXffHMMH@M@HHHWkbWWWWbbkkHHWH90z<<~~~.......",
    "yZyZyWWHkWVWHHHMMggggqqqqHHHWWHWUC<<:~~~..........",
    "yyZZZyyVWbHpppbbbkkkkqqHHBY967<<~~~~...........`.`",
    "ZZZZZZyyyVpppbkkqqqH9Vz=<<<:~~~~~............`..`.\n"
};

const unsigned int STRINGS_COUNT = 18u;

void puts_yaju_aa(){
    
    for(unsigned int i = 0u; i < STRINGS_COUNT; i++){
        puts(yaju_aa[i]);
    }

    return;
}

int main(int argc,char* argv[]){
    if(argc > 1){
        if(strcmp(argv[1],"--get_yajuaa") == 0) puts_yaju_aa();
    }

    puts("ikisugi, yarimasune!! :)!! 114514\n");

    return 0;
} 