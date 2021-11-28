#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Cach_Buffer
{
    char sayfa[20];
    int sayac;
    struct Cach_Buffer* next;
    struct Cach_Buffer* prev;
};

void Add_node(struct Cach_Buffer** head, char sayfa[])
{
    struct Cach_Buffer* new_node = (struct Cach_Buffer*)malloc(sizeof(struct Cach_Buffer));

    strcpy(new_node->sayfa,sayfa);
    new_node->sayac=1;

    new_node->prev=NULL;
    new_node->next=NULL;

    if((*head)==NULL)
    {
        (*head)=new_node;
        return;
    }

    (*head)->prev=new_node;
    new_node->next=(*head);
    (*head)=new_node;
}

void delete_node(struct Cach_Buffer** head)
{
    struct Cach_Buffer* temporary = (*head);

    if (temporary == NULL)
    {
        return;
    }

    if ( temporary->next == NULL)
    {
        free(temporary);
    }

    while( temporary->next->next != NULL)
    {
        temporary = temporary->next;
    }

    free(temporary->next);
    temporary->next = NULL;
}

void print_nodes(struct Cach_Buffer* head)
{
    struct Cach_Buffer* temporary = head;

    while(temporary != NULL)
    {
        printf("%s, ", temporary->sayfa);
        printf("%d<->", temporary->sayac);
        temporary=temporary->next;
    }
    if(head == NULL)
    {
        printf("List is Empty\n");
    }
}

int does_exist(struct Cach_Buffer* head, char sayfa[])
{
    struct Cach_Buffer* temporary = head;

    while(temporary != NULL)
    {
        if(!strcmp(sayfa,temporary->sayfa))
        {
            (temporary->sayac)++;
            return 1;
        }
        temporary=temporary->next;
    }
    return 0;
}

void threshold_check(struct Cach_Buffer** head, int T, char sayfa[])
{
    struct Cach_Buffer* temporary = (*head);

    while(temporary != NULL)
    {
        if ((temporary->sayac) > T && !strcmp(temporary->sayfa,sayfa) )
        {
            int check = 0;
            while ( temporary->prev != NULL)
            {
                char t[20];
                strcpy(t, temporary->sayfa);
                strcpy(temporary->sayfa, temporary->prev->sayfa);
                strcpy(temporary->prev->sayfa, t);

                int tmp = temporary->sayac;
                temporary->sayac = temporary->prev->sayac;
                temporary->prev->sayac = tmp;
                temporary = temporary->prev;
            }
            if ( check )
                (*head) = temporary;
        }
        temporary = temporary->next;
    }

}

int check_capacity(struct Cach_Buffer* head, int L)
{
    struct Cach_Buffer* temporary = head;
    int count=0;

    while ( temporary != NULL)
    {
        count++;
        temporary = temporary->next;
    }

    if (count == L)
    {
        return 1;
    }
    return 0;
}

void clean_list(struct Cach_Buffer** head)
{
    struct Cach_Buffer* temporary = (*head);
    struct Cach_Buffer* tmp;

    while(temporary != NULL)
    {
        tmp = temporary->next;
        free(temporary);
        temporary = tmp;
    }

    (*head) = NULL;

}

void main_program_file(struct Cach_Buffer** head)
{
    int T,L;char sayfa[20];char bos[20];char filename[100];
    printf("Enter the File path WITH .txt at the End\n");
    scanf(" %s",filename);
    FILE *fp;
    fp = fopen(filename,"r");
    if ( fp == NULL)
    {
        printf("Could not Open\n");
        return ;
    }
    fscanf(fp, "%d", &T);
    fscanf(fp, "%d", &L);

    printf("T is : %d\nL is : %d\n",T,L);
    fgets(bos,20,fp);
    fgets( sayfa, 20, fp);


    int len = strlen(sayfa);
    if (sayfa[len-1] == '\n')
    {
        sayfa[len-1] = '\0';
    }

    Add_node(head,sayfa);
    printf("The List is :\n");
    print_nodes(*head);
    printf("\n");


    while( !feof(fp) )
    {
        fgets(sayfa , 6, fp);
        len = strlen(sayfa);
        if (sayfa[len-1] == '\n')
        {
            sayfa[len-1] = '\0';
        }
        if( !does_exist(*head,sayfa) )
        {
            if ( check_capacity(*head,L) )
            {
                delete_node(head);
                Add_node(head,sayfa);
                print_nodes(*head);
                printf("\n\n");

            }
            else
            {
                Add_node(head,sayfa);
                print_nodes(*head);
                printf("\n\n");
            }

        }
        threshold_check(head,T,sayfa);
        print_nodes(*head);
        printf("\n\n");

    }
    fclose(fp);
}

void main_program_Console(struct Cach_Buffer** head, int T, int L)
{
    char sayfa[20];
    printf("Enter Your Page Request:\n");
    scanf("%s",sayfa);

    if( !does_exist(*head,sayfa) )
    {
        if ( check_capacity(*head,L) )
        {
            delete_node(head);
            Add_node(head,sayfa);
            print_nodes(*head);
            printf("\n\n");
            return;
        }
        Add_node(head,sayfa);
        print_nodes(*head);
        printf("\n\n");
        return;
    }
    threshold_check(head,T,sayfa);
    print_nodes(*head);
    printf("\n\n");

}

int main()
{
    int T, L; char sayfa[20];char x;char y;
    struct Cach_Buffer* head = NULL;

    printf("Choose an Option and Press Enter\n");
    printf(" Press 'A' to Read from Text File\n Press 'B' to Read from Console\n Press 'C' to Clean the List\n Press 'D' to Exit\n");
    scanf(" %c",&y);

    switch(y)
    {
        case 'A':{
                    main_program_file(&head);
                    return main();
                 }
        case 'a':{
                    main_program_file(&head);
                    return main();
                 }
        case 'B':{
                    break;
                 }
        case 'b':{
                    break;
                 }
        case 'C': {clean_list(&head);
                    print_nodes(head);
                    return main();
                    break;}
        case 'c': {clean_list(&head);
                    print_nodes(head);
                    return main();
                    break;};
        case 'D': return 0;
        case 'd': return 0;
        default : break;
    }

    printf("Enter the Length (L) of the List\n");
    scanf("%d",&L);
    printf("Enter the Threshold (T) of the List\n");
    scanf("%d",&T);

    printf("Enter your Page Request\n");
    scanf("%s",sayfa);

    Add_node(&head,sayfa);
    printf("The List is :\n");
    print_nodes(head);
    printf("\n\n\n");

    while(1)
    {
        printf("Choose an Option and Press Enter\n");
        printf(" Press 'A' to ADD Request\n Press 'B' to Clean the List\n Press 'C' to Exit\n");
        scanf(" %c",&x);

        switch (x)
        {
            case 'A': {
                        main_program_Console(&head,T,L);
                        break;
                      }
            case 'a':{
                        main_program_Console(&head,T,L);
                        break;
                     }
            case 'B':{
                        clean_list(&head);
                        print_nodes(head);
                        break;
                     }
            case 'b':{
                        clean_list(&head);
                        print_nodes(head);
                        break;
                     }
            case 'C': return 0;
            case 'c': return 0;
            default : break;
        }
    }
    return 0;
}
