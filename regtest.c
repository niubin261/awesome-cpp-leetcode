//
// Created by niubin on 18-4-30.
//
#include <stdio.h>
#include <string.h>
#include <regex.h>
#include <assert.h>
#include <stdlib.h>
#include <elf.h>
#include <stdarg.h>
// 提取子串
char *getsubstr(char *s, regmatch_t *pmatch) {
    static char buf[100] = {0};
    memset(buf, 0, sizeof(buf));
    memcpy(buf, s + pmatch->rm_so, pmatch->rm_eo - pmatch->rm_so);

    return buf;
}

char *control_match(char *buf) {
    const char *pattern = "apply*";
    regmatch_t pmatch[2];
    char *ptr = NULL;
    regex_t reg;
    assert(regcomp(&reg, pattern, REG_EXTENDED | REG_NEWLINE) == 0);
    int status = regexec(&reg, buf, 2, pmatch, 0);

    if (status == REG_NOMATCH) {
        return NULL;
    } else if (pmatch[0].rm_so != -1) {
        (ptr) = buf + pmatch[0].rm_so;
    }
    regfree(&reg);
    return ptr;

}
//int main(void) {
//    regmatch_t pmatch;
//    regex_t reg;
//    const char *pattern = "[a-z]+";        // 正则表达式
//    char buf[] = "HELLOsaiYear2012@gmail.com";    // 待搜索的字符串
//
//    regcomp(&reg, pattern, REG_EXTENDED);    //编译正则表达式
//    int offset = 0;
//    while (offset < strlen(buf)) {
//        int status = regexec(&reg, buf + offset, 1, &pmatch, 0);
//        /* 匹配正则表达式，注意regexec()函数一次只能匹配一个，不能连续匹配，网上很多示例并没有说明这一点 */
//        if (status == REG_NOMATCH)
//            printf("No Match\n");
//        else if (pmatch.rm_so != -1) {
//            printf("Match:\n");
//            char *p = getsubstr(buf + offset, &pmatch);
//            printf("[%d, %d]: %s\n", offset + pmatch.rm_so + 1, offset + pmatch.rm_eo, p);
//        }
//        offset += pmatch.rm_eo;
//    }
//    regfree(&reg);        //释放正则表达式
//    const char *b = "control ingress{\n"
//            "apply(fwd_table);\n"
//            "}\n"
//            "control egress{\n"
//            "apply\n"
//            "}";
//    char *p1;
//    char *p2;
//    p1 = control_match(b);
//    p2 = control_match(p1 + 1);
//    printf("%c %c\n",*p1);
//
//    return 0;
//}
void pof_safe_free_mem(int n_values, ...) {
    va_list var_arg;
    uint8_t cnt;
    va_start(var_arg, n_values);
    for (cnt = 0; cnt < n_values; cnt++) {
        void *ptr = va_arg(var_arg, void*);
        free(ptr);
        ptr = NULL;
    }
    va_end(var_arg);
    return;
}
int main() {

//    int a = 0x11223344;
//    char *p = (char *)&a;
//    printf("%x\n",*p);
//    unsigned char b = 1;
//    b = ~b;
//    printf("%d\n",b);
//    FILE *f = fopen("test.py","r");
//
//    printf("%d\n",system("sudo python tesx.py"));
//
//    fclose(f);
//    fclose(f);
//    if (f == NULL){
//        printf("The f is NULL");
//    }
////
////    if (feof(f)) {
////
////        fclose(f);
////    }
//    regex_t reg;
//    const char *str = "<k1>v1</k1><k2>v2</k2><k3>v3</k3>";
//    assert(regcomp(&reg, "<([^>]*)>([^<]*)</\\1>", REG_EXTENDED) == 0);
//    const int nr_match = 3;
//    regmatch_t matches[nr_match];
//    int i,j;
//    const char *start = str;
//    while (1) {
//        int ret = regexec(&reg, start, nr_match, matches, 0);
//        if (ret == 0)
//        {
//            for (i = 0; i < nr_match; i++)
//            {
//                for (j = matches[i].rm_so; j < matches[i].rm_eo; j++)
//
//
//
//
//          putchar(start[j]);
//                putchar('\n');
//            }
//            start += matches[0].rm_eo;  //下次从 这次匹配末尾 开始搜索
//            continue;
//        }
//        if (ret == REG_NOMATCH)
//            printf("no match\n");
//        else {
//            char msgbuf[256];
//            regerror(ret, &reg, msgbuf, sizeof(msgbuf));
//            printf("error: %s\n", msgbuf);
//        }
//        break;
//    }
//    regfree(&reg);
//    return 0;
    char *buf_tmp_control = (char *) malloc(sizeof(char) * 100 * 10);
#define VALID_FLAG(x) "my_metadata.field"#x
    printf("%s", VALID_FLAG(1));
    pof_safe_free_mem(1,buf_tmp_control);
    if (buf_tmp_control == NULL){
        printf("true");
    }
}