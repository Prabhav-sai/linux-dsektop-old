#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef enum accounttype{
    savings,
    current,
}accounttype;

typedef struct AccountInfo{
    int AccountNumber;
    accounttype AccountType;
    char Name[50];
    float Balance;
}AccountInfo;

typedef struct Accountnode{
    AccountInfo Account;
    struct Accountnode * next;
}Accountnode;

typedef Accountnode* LinkedList;

void display(LinkedList Accountlist){
    if(Accountlist==NULL){
        printf("No Accounts to display\n");
        return ;
    }
    printf("Account Number  Account Type    Name          Balance\n");
    printf("--------------------------------------------------------\n");
    while(Accountlist!=NULL){
        printf("%d\t\t",Accountlist->Account.AccountNumber);
        if(Accountlist->Account.AccountType==0) printf("savings\t\t");
        else printf("current\t\t");
        printf("%s\t\t%.2f\n",Accountlist->Account.Name,Accountlist->Account.Balance);
        Accountlist=Accountlist->next;
    }
    return ;
}

void lowBalanceAccounts(LinkedList AccountList){
    int flag =0;
    if(AccountList==NULL){
        printf("No Low Balance Accounts\n");
        return ;
    }
    while(AccountList!=NULL){
        if(AccountList->Account.Balance<100){
            printf("Account Number: %d, Name: %s, Balance : %.2f\n",AccountList->Account.AccountNumber,AccountList->Account.Name,AccountList->Account.Balance);
            flag++;
        }
        AccountList=AccountList->next;
    }
    if(flag==0){
        printf("No Low Balance Accounts\n");
    }
    return;
}

void PrintNode(AccountInfo Account){
    printf("Account Number: %d\n",Account.AccountNumber);
    printf("Account Holder: %s\n",Account.Name);
    printf("Account Type: ");
    if(Account.AccountType==0) printf("savings\n");
    else printf("current\n");
    printf("Balance: Rs %.2f\n",Account.Balance);
    return;
}

int CheckNode(LinkedList AccountList,char Name[],accounttype AccountType){
    int flag =0;
    if(AccountList==NULL) return -10;
    while(AccountList->next!=NULL){
        if(AccountList->Account.AccountType==AccountType&&strcmp(AccountList->Account.Name,Name)==0){
            flag =AccountList->Account.AccountNumber;
            break;
        }
        AccountList=AccountList->next;
    }
    if(AccountList->Account.AccountType==AccountType&&strcmp(AccountList->Account.Name,Name)==0){
        flag =AccountList->Account.AccountNumber;
    }
    return flag;
}

LinkedList createAccount(LinkedList AccountList,accounttype AccountType,char Name[],float Amount){
    LinkedList temp = AccountList;
    Accountnode* Node = (Accountnode*)malloc(sizeof(Accountnode));
    Node->Account.AccountType= AccountType;
    Node->Account.Balance = Amount;
    strcpy(Node->Account.Name,Name);
    if(AccountList==NULL){
        Node->Account.AccountNumber=100;
        Node->next=NULL;
        AccountList = Node;
        PrintNode(Node->Account);
        return Node;
    }
    if(CheckNode(AccountList,Name,AccountType)!=0){
        printf("Invalid: User already exists!\n");
        return AccountList;
    }
    if(AccountList->Account.AccountNumber!=100){
        Node->Account.AccountNumber=100;
        Node->next=AccountList;
        PrintNode(Node->Account);
        return Node;
    }
    int numbercheck=100;
    while(AccountList->next!=NULL&&(numbercheck+1)==(AccountList->next)->Account.AccountNumber){
        numbercheck++;
        AccountList=AccountList->next;
    }
    numbercheck++;
    Node->Account.AccountNumber=numbercheck;
    Node->next=AccountList->next;
    AccountList->next=Node;
    PrintNode(Node->Account);
    return temp;
}

LinkedList deleteAccount(LinkedList AccountList,accounttype AccountType,char Name[]){
    LinkedList temp = AccountList;
    int check=CheckNode(AccountList,Name,AccountType);
    if(check==0||check==-10){
        printf("Invalid: User does not exist\n");
        return temp;
    }
    if(AccountList->Account.AccountNumber==check){
        printf("Account deleted successfully\n");
        free(AccountList);
        return AccountList->next;
    }
    while(AccountList->next!=NULL&&check!=(AccountList->next)->Account.AccountNumber){
        AccountList=AccountList->next;
    }
    LinkedList freel = AccountList->next;
    AccountList->next=(AccountList->next)->next;
    printf("Account deleted successfully\n");
    free(freel);
    return temp;
}

void transaction(LinkedList AccountList,int AccountNumber,float Amount,int code){
    int flag = 0;
    if(AccountList==NULL){
        printf("Invalid: User does not exist\n");
        return;
    }
    while(AccountList->Account.AccountNumber!=AccountNumber&&AccountList->next!=NULL){
        if(AccountList->Account.AccountNumber==AccountNumber){
            flag = 1;
        }
        AccountList=AccountList->next;
    }
    if(AccountList->Account.AccountNumber==AccountNumber){
        flag = 1;
    }
    if(flag==0){
        printf("Invalid: User does not exist\n");
        return ;
    }
    if(code==0){
        if(AccountList->Account.Balance-Amount<100){
            printf("The balance is insufficient for the specified withdrawal.\n");
            return;
        }
        else{
            AccountList->Account.Balance -= Amount;
        }
    }
    if(code==1){
        AccountList->Account.Balance += Amount;
    }
    printf("Updated balance is Rs %.2f\n",AccountList->Account.Balance);
    return ;
}

int main(){
    LinkedList AccountList=NULL;
    char command[11];
    accounttype AccountType;
    char preaccounttype[10];
    char Name[50];
    float Amount;
    int AccountNumber;
    int code;
    while(1){
        scanf("%s",command);
        if(strcmp(command,"CREATE")==0){
            scanf("%s %s %f",preaccounttype,Name,&Amount);
            if(strcmp(preaccounttype,"savings")==0) AccountType = savings;
            else AccountType = current;
            AccountList=createAccount(AccountList,AccountType,Name,Amount);
        }
        if(strcmp(command,"DELETE")==0){
            scanf("%s %s",preaccounttype,Name);
            if(strcmp(preaccounttype,"savings")==0) AccountType = savings;
            else AccountType = current;
            AccountList=deleteAccount(AccountList,AccountType,Name);
        }
        if(strcmp(command,"TRANSACTION")==0){
            scanf("%d %f %d",&AccountNumber,&Amount,&code);
            transaction(AccountList,AccountNumber,Amount,code);
        }
        if(strcmp(command,"LOWBALANCE")==0){
            lowBalanceAccounts(AccountList);
        }
        if(strcmp(command,"DISPLAY")==0){
            display(AccountList);
        }
        if(strcmp(command,"EXIT")==0){
            break;
        }
    }
    return 0;
}