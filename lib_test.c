#include <mem.h>
#include "m_string.h"

int predicat(char c) {
    return 'o' < c && c < 't';
}

void test_lib(){
    int passed = 0;
    int counter=1;

    my_str_t str, str1, str2;

//    my_str_create
    my_str_create(&str, 10);

    if (str.size_m == 0) passed++;
    else printf("%d. Failed [my_str_create]\n", counter);
    counter++;


    if (str.capacity_m == 10) passed++;
    else printf("%d. Failed [my_str_create]\n", counter);
    counter++;

//    my_str_from_cstr
    my_str_from_cstr(&str, "test", 0);

    if (str.capacity_m == 4) passed++;
    else printf("%d. Failed [my_str_from_cstr]\n", counter);
    counter++;

    my_str_from_cstr(&str, "test", 10);
    if (str.capacity_m == 10) passed++;
    else printf("%d. Failed [my_str_from_cstr]\n", counter);
    counter++;

    if (str.size_m == 4) passed++;
    else printf("%d. Failed [my_str_from_cstr]\n", counter);
    counter++;



// my_str_size
    if (my_str_size(&str)==4) passed++;
    else printf("%d. Failed [my_str_size]\n", counter);
    counter++;


// my_str_capacity
    if (my_str_capacity(&str)==10) passed++;
    else printf("%d. Failed [my_str_capacity]\n", counter);
    counter++;


// my_str_getc
    if (my_str_getc(&str, 1)=='e') passed++;
    else printf("%d. Failed [my_str_getc]\n",counter);
    counter++;

// my_str_putc
    my_str_putc(&str, 3, '!');
    if (my_str_getc(&str, 3)=='!') passed++;
    else printf("%d. Failed [my_str_putc]\n",counter);
    counter++;

// my_str_pushback
    my_str_pushback(&str, '?');
    if (my_str_getc(&str, 4)=='?') passed++;
    else printf("%d. Failed [my_str_pushback]\n",counter);
    counter++;

// my_str_popback
    if (my_str_popback(&str)=='?') passed++;
    else printf("%d. Failed [my_str_popback]\n",counter);
    counter++;


// my_str_free
    my_str_free(&str);
    if (str.size_m == 0 && str.capacity_m==0 && str.data==0) passed++;
    else printf("%d. Failed [my_str_free]\n",counter);
    counter++;

// my_str_empty
    if (my_str_empty(&str)==1) passed++;
    else printf("%d. Failed [my_str_empty]\n",counter);
    counter++;

// my_str_cmp
    my_str_from_cstr(&str, "test", 0);
    my_str_from_cstr(&str1, "Test",0);

    if (my_str_cmp(&str, &str)==0) passed++;
    else printf("%d. Failed [my_str_cmp]\n",counter);
    counter++;

    if (my_str_cmp(&str, &str1)==1) passed++;
    else printf("%d. Failed [my_str_cmp]\n",counter);
    counter++;

    if (my_str_cmp(&str1, &str)==-1) passed++;
    else printf("%d. Failed [my_str_cmp]\n",counter);
    counter++;

    my_str_from_cstr(&str1, "tes",10);

    if (my_str_cmp(&str, &str1)==1) passed++;
    else printf("%d. Failed [my_str_cmp]\n",counter);
    counter++;

// my_str_clear
    my_str_clear(&str1);

    if (str1.size_m==0 && str1.capacity_m == 10) passed++;
    else printf("%d. Failed [my_str_clear]\n",counter);
    counter++;

// my_str_copy
    my_str_from_cstr(&str, "test", 10);
    my_str_copy(&str, &str1, 1);
    if (str1.size_m==4 && str1.capacity_m == 10 && my_str_cmp(&str, &str1)==0) passed++;
    else printf("%d. Failed [my_str_copy]\n",counter);
    counter++;

    my_str_copy(&str, &str1, 0);
    if (str1.size_m==4 && str1.capacity_m == 4 && my_str_cmp(&str, &str1)==0) passed++;
    else printf("%d. Failed [my_str_copy]\n",counter);
    counter++;

// my_str_insert_c
    my_str_insert_c(&str, '!', 2);
    my_str_from_cstr(&str1, "te!st", 0);
    if (my_str_cmp(&str, &str1)==0) passed++;
    else printf("%d. Failed [my_str_insert_c]\n",counter);
    counter++;

// my_str_insert
    my_str_from_cstr(&str1, "123", 0);
    my_str_insert(&str, &str1, 3);
    my_str_from_cstr(&str2, "te!123st", 0);
    if (my_str_cmp(&str, &str2)==0) passed++;
    else printf("%d. Failed [my_str_insert]\n",counter);
    counter++;

// my_str_insert_cstr
    my_str_from_cstr(&str, "test", 20);
    my_str_insert_cstr(&str, "123", 2);
    my_str_from_cstr(&str2, "te123st", 0);
    if (my_str_cmp(&str, &str2)==0) passed++;
    else printf("%d. Failed [my_str_insert_cstr]\n",counter);
    counter++;

// my_str_append
    my_str_from_cstr(&str1, "?!", 10);
    my_str_append(&str, &str1);
    my_str_from_cstr(&str2, "te123st?!", 0);
    if (my_str_cmp(&str, &str2)==0) passed++;
    else printf("%d. Failed [my_str_append]\n",counter);
    counter++;

// my_str_append_cstr
    my_str_append_cstr(&str, "{}");
    my_str_from_cstr(&str2, "te123st?!{}", 0);
    if (my_str_cmp(&str, &str2)==0) passed++;
    else printf("%d. Failed [my_str_append_cstr]\n",counter);
    counter++;

// my_str_substr
    my_str_create(&str1, 10);
    my_str_substr(&str, &str1, 3,6);
    my_str_from_cstr(&str2, "23s", 0);
    if (my_str_cmp(&str1, &str2)==0) passed++;
    else printf("%d. Failed [my_str_substr]\n",counter);
    counter++;

    my_str_substr(&str, &str1, 3,100);
    my_str_from_cstr(&str2, "23st?!{}", 0);
    if (my_str_cmp(&str1, &str2)==0) passed++;
    else printf("%d. Failed [my_str_substr]\n",counter);
    counter++;

// my_str_get_cstr
    if (strcmp(my_str_get_cstr(&str), "te123st?!{}")==0) passed++;
    else printf("%d. Failed [my_str_get_cstr]\n",counter);
    counter++;

// my_str_find
    my_str_from_cstr(&str1, "st?", 0);
    if (my_str_find(&str, &str2, 2)==5) passed++;
    else printf("%d. Failed [my_str_find]\n",counter);
    counter++;

// my_str_find_c
    if (my_str_find_c(&str, '3', 2)==4) passed++;
    else printf("%d. Failed [my_str_find_c]\n",counter);
    counter++;

// my_str_find_if
    my_str_from_cstr(&str, "abcdefqds", 0);
    if (my_str_find_if(&str, predicat)==6) passed++;
    else printf("%d. Failed [my_str_find_if]\n",counter);
    counter++;

// my_str_read_file
    my_str_create(&str, 10);
    my_str_read_file(&str, fopen("test_0.txt","r"));
    my_str_from_cstr(&str1, "abc", 0);
    if (my_str_cmp(&str, &str1)==0) passed++;
    else printf("%d. Failed [my_str_read_file]\n",counter);
    counter++;

    my_str_read_file(&str, fopen("test_1.txt","r"));
    my_str_from_cstr(&str1, "abcdefghji", 0);
    if (my_str_cmp(&str, &str1)==0) passed++;
    else printf("%d. Failed [my_str_read_file]\n",counter);
    counter++;




    printf("[%d/%d] Passsed", passed, counter-1);
}

int main() {

    test_lib();
    return 0;
}