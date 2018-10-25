#include "m_string.h"

#include <stdlib.h>


int my_str_create(my_str_t* str, size_t buf_size) {
    str-> size_m=0;
    str->data = malloc(buf_size+1);
    if (!str->data)
        return -1;
    str->capacity_m = buf_size;
    return 0;
}

int my_str_from_cstr(my_str_t* str, const char* cstr, size_t buf_size) {
    int len = 0;
    while(cstr[len]!='\0') {
        len++;
    }

    if (buf_size==0) {
        int res=my_str_create(str, len);
        if (res==-1) {
            return -2;
        }
        int i=0;
        while(cstr[i]!='\0') {
            str->data[i] = cstr[i];
            i++;
        }
        str->size_m=len;
    } else if (buf_size<len) {
        return -1;

    } else {
        int res=my_str_create(str, buf_size);
        if (res==-1) {
            return -2;
        }
        int i=0;
        while(cstr[i]!='\0') {
            str->data[i] = cstr[i];
            i++;
        }
        str->size_m=len;
    }

    return 0;



}

void my_str_free(my_str_t* str) {
    free(str->data);
    str->data=0;
    str->size_m=0;
    str->capacity_m=0;
}

size_t my_str_size(const my_str_t* str) {
    return str->size_m;
}

size_t my_str_capacity(const my_str_t* str) {
    return str->capacity_m;
}

int my_str_empty(const my_str_t* str) {
    return str->size_m==0;
}

int my_str_getc(const my_str_t* str, size_t index) {
    if (str->size_m <= index) {
        return -1;
    } else {
        return str->data[index];
    }
}

int my_str_putc(my_str_t* str, size_t index, char c) {
    if (index < str->size_m) {
        str->data[index]=c;
        return 0;
    } else {
        return -1;
    }
}

int my_str_pushback(my_str_t* str, char c) {
    if (str->size_m<str->capacity_m) {
        str->data[str->size_m++]=c;
        return 0;
    } else {
        return -1;
    }
}

int my_str_popback(my_str_t* str) {
    if (str->size_m > 0) {
        return str->data[--str->size_m];

    } else {
        return -1;
    }
}

int my_str_copy(const my_str_t* from,  my_str_t* to, int reserve){
    if (reserve) {
        my_str_create(to, from->capacity_m);
    } else {
        my_str_create(to, from->size_m);
    }

    for (int i = 0; i < from->size_m; ++i) {
        to->data[i]=from->data[i];
    }

    to->size_m=from->size_m;

    return 0;

}

void my_str_clear(my_str_t* str) {
    str->size_m=0;
}

int my_str_insert_c(my_str_t* str, char c, size_t pos) {

    if ( pos+1 > str->size_m || str->size_m+1>str->capacity_m) {
        return -1;
    }
    for (int i = str->size_m; i > pos; i--) {
        str->data[i]=str->data[i-1];
    }
    str->data[pos]=c;
    str->size_m++;
    return 0;
}

int my_str_insert(my_str_t* str, const my_str_t* from, size_t pos) {
    if (from->size_m + str->size_m > str->capacity_m || pos+1 > str->size_m) {
        return -1;
    }

    for (int i = str->size_m; i > pos; i--) {
        str->data[i+from->size_m-1]=str->data[i-1];
    }

    for (int i = 0; i < from->size_m; i++) {
        str->data[pos+i]=from->data[i];
    }

    str->size_m+=from->size_m;
    return 0;
}

int my_str_insert_cstr(my_str_t* str, const char* from, size_t pos) {
    int len = 0;
    while(from[len]!='\0') {
        len++;
    }

    if (len+ str->size_m > str->capacity_m || pos+1 > str->size_m) {
        return -1;
    }

    for (int i = str->size_m; i > pos; i--) {
        str->data[i+len-1]=str->data[i-1];
    }

    for (int i = 0; i < len; i++) {
        str->data[pos+i]=from[i];
    }

    str->size_m+=len;
    return 0;
}

int my_str_append(my_str_t* str, const my_str_t* from) {
    if (from->size_m+ str->size_m > str->capacity_m ) {
        return -1;
    }

    for (int i = 0; i < from->size_m; ++i) {
        str->data[str->size_m+i] = from->data[i];
    }

    str->size_m+=from->size_m;
    return 0;
}

int my_str_append_cstr(my_str_t* str, const char* from) {
    int len = 0;
    while(from[len]!='\0') {
        len++;
    }

    if (len+ str->size_m > str->capacity_m ) {
        return -1;
    }

    for (int i = 0; i < len; ++i) {
        str->data[str->size_m+i] = from[i];
    }

    str->size_m+=len;
    return 0;
}

int my_str_cmp(my_str_t* str1, my_str_t* str2){
    int iter;
    if (str1->size_m == str2->size_m) {
        iter=str1->size_m;
    } else if (str1->size_m > str2->size_m) {
        iter = str2->size_m;
    } else {
        iter = str1->size_m;
    }

    for (int i = 0; i < iter; ++i) {
        if (str1->data[i] < str2->data[i]) {
            return -1;
        } else if (str1->data[i] > str2->data[i]) {
            return 1;
        }
    }


    if (str1->size_m == str2->size_m) {
        return 0;
    } else if (str1->size_m > str2->size_m) {
        return 1;
    } else {
        return -1;
    }

}

int my_str_substr(const my_str_t* str, my_str_t* to, size_t beg, size_t end) {

    size_t end_p;

    if (end > str->size_m) {
        end_p=str->size_m;
    } else {
        end_p= end;
    }
    if (beg > str->size_m - 1 || beg>=end || end_p-beg>  to->capacity_m) {
        return -1;
    }


    for (int i = 0; i < end_p-beg; ++i) {
       to->data[i] = str->data[i+beg];
    }

    to->size_m = end_p-beg;

    return 0;
}

const char* my_str_get_cstr(my_str_t* str) {
    str -> data[str->size_m] = '\0';
    return str->data;
}

size_t my_str_find(const my_str_t* str, const my_str_t* tofind, size_t from) {
    if (from > str->size_m-1) {
        return -1;
    }
    int counter;
    for (int i = from; i < str->size_m; ++i) {
        if (str->data[i] == tofind->data[0]) {
            counter=0;
            for (int j = 0; j < tofind->size_m; ++j) {
                if (str->data[i+j]!=tofind->data[j]) {
                    break;
                } else {
                    counter++;
                }
            }

            if (counter == tofind->size_m) {
                return i+from;
            }


        }
    }
    return -1;
}

size_t my_str_find_c(const my_str_t* str, char tofind, size_t from){
    if (from > str->size_m-1) {
        return -1;
    }

    for (int i = from; i < str->size_m; ++i) {
        if (str->data[i]==tofind) {
            return i;
        }
    }

    return -1;
}

size_t my_str_find_if(const my_str_t* str, int (*predicat)(char)) {
    for (int i = 0; i < str->size_m; ++i) {
        if (predicat(str->data[i])) {
            return i;
        }
    }
    return -1;
}

size_t my_str_read_file(my_str_t* str, FILE* file) {
    if (file == NULL)
    {
        fclose(file);
        return -1;
    }

    char * data = fgets(str->data, str->capacity_m+1, file);
    str->size_m=0;

    int counter=0;
    while(str->data[counter] != '\0' && counter < str->capacity_m) {

        counter++;
    }

    str->size_m=counter;
    fclose(file);

    return 0;


}

size_t my_str_read(my_str_t* str){

    char * data = fgets(str->data, str->capacity_m+1, stdin);
    str->size_m=0;

    int counter=0;
    while(str->data[counter] != '\n' && counter < str->capacity_m) {

        counter++;
    }

    str->size_m=counter;


    return 0;
}




