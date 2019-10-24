#include <stdio.h>
#include<string.h>
#include<stdlib.h>
/* aisha umar musa 171103035*/
int nextid(int* idno); // ...
struct registerr
{
	char name[20];
	char surname[20];
	char gender[20];
	int age;
	char status[20];
	int id;
}patient[100];

int main()
{
 	FILE *pat;
 	FILE *hold;
 	int idno,n,search,i;
 	int statuschange,searchid;
 	int cont,count,menu;
 	char searchsurname[20];
 	char patientname[20],patientsurname[20];
 	int filehold, totalpatients;
	int patient_was_found;
 	int con=2;
 	do
 	{
 		//pat=fopen("nizamiye_hospital.txt","r");
		pat=fopen("nizamiye_hospital.txt","a+");
		//for(i=0;!feof(pat);i++)
		i = 0;
		// Copy everything inside the file into the patient array
		// As we're copying, we're counting how many patients were in the file.
		while (fscanf(pat,"%s %s %s %d %s %d",
				&patient[i].name,&patient[i].surname,
				&patient[i].gender,&patient[i].age,
				&patient[i].status,&patient[i].id) == 6)
		{
			//fscanf(pat,"%s %s %s %d %s %d",&patient[i].name,&patient[i].surname,&patient[i].gender,&patient[i].age,&patient[i].status,&patient[i].id);
			/*if(patient[i].id == patient[i+1].id)
				{

					idno=patient[i].id+1;
				}*/
			i++;
		}
		totalpatients = i;
		// The last patient's ID;
		// For example if you've registered 5 people before
		// Then the last patient's ID is 5
		idno = totalpatients;
		fclose(pat);
		//fclose(pat);

		system("cls");
		printf(" MENU:\n1.Register patient\n2.Display all admitted patients \n3.Search for a patient\n4.Change status of a patient\n5.filter out patients\n6.Close the program\n");
		printf("Enter your menu\n");
		scanf("%d",&menu);
		switch (menu)
		{
			case 1:
				system("cls");
				pat=fopen("nizamiye_hospital.txt","a+");
				printf("enter the number of patients to register");
				scanf("%d",&n);
				//for (i=1;i<=n;i++)
				for (i=totalpatients;i<(totalpatients + n);i++)
				{
				  	patient[i].id=nextid(&idno);
				  	//idno=patient[i].id;
				  	printf("enter the patients firstname\n");
				  	scanf("%s",&patient[i].name);
				  	printf("enter the patients lastname\n");
				  	scanf("%s",&patient[i].surname);
				  	printf("enter the patients gender\n");
				  	scanf("%s",&patient[i].gender);
				  	printf("enter patients age\n");
				  	scanf("%d",&patient[i].age);
				  	printf("enter patients status\n");
				  	//scanf("%d",&patient[i].status);
					scanf("%s",&patient[i].status);

				  	//fprintf(pat,"%s %s %s %d %s %d\n",&patient[i].name,&patient[i].surname,&patient[i].gender,&patient[i].age,&patient[i].status,&patient[i].id);
					fprintf(pat,"%s %s %s %d %s %d\n",patient[i].name,patient[i].surname,patient[i].gender,patient[i].age,patient[i].status,patient[i].id);
				    printf("the patient has been registered successfully\n");

	           	}
				   totalpatients = totalpatients + n;
	           	 fclose(pat);

	           	 break;
	        case 2:
				system("cls");
				for (i=0;i<totalpatients;i++)
				{
					//fscanf(pat,"%s %s %s %d %s %d",&patient[i].name,&patient[i].surname,&patient[i].gender,&patient[i].age,&patient[i].status,&patient[i].id);
					if (strcmp(patient[i].status,"admitted")==0) {
						printf("%s %s %s %d %s %d\n",patient[i].name,patient[i].surname,patient[i].gender,patient[i].age,patient[i].status,patient[i].id);
					}
				}
	            break;
	        case 3:
				system("cls");
	        	printf("1.search by surname\n2.search by id");
	        	scanf("%d",&search);
	        	if(search==1)
	        	{
	        		printf("enter the surname of the patient");
	        		scanf("%s",&searchsurname);
				}
				if (search==2)
				{
					printf("enter the id of the patient");
					scanf("%d",&searchid);
				}
				//for(i=0;!feof(pat);i++)
				/*while (fscanf(pat,"%s %s %s %d %s %d",
						&patient[i].name,&patient[i].surname,&patient[i].gender,
						&patient[i].age,&patient[i].status,&patient[i].id) == 6)*/
				patient_was_found = 0;
				for(i=0;i<totalpatients;i++)
				{
					if (search==1)
					{
						if(strcmp(patient[i].surname,searchsurname)==0)
						{
							printf("%s %s %s %d %s %d\n",patient[i].name,patient[i].surname,patient[i].gender,patient[i].age,patient[i].status,patient[i].id);
							patient_was_found = 1;
						}
						//else if(feof(pat) && strcmp(patient[i].surname,searchsurname)!=0 )
						else if(i==totalpatients-1 && patient_was_found == 0)
						{
							printf("the name was not found\n");
						}

					}
					else if(search==2)
					{
						if(patient[i].id == searchid)
						{
							printf("%s %s %s %d %s %d\n",patient[i].name,patient[i].surname,patient[i].gender,patient[i].age,patient[i].status,patient[i].id);
							break;
						}
						//if (feof(pat) && patient[i].id!=searchid);
						else if (i==totalpatients-1 && patient[i].id!=searchid)
						{
							printf("the id number was not found\n");
						}

					}
				}
	            break;
			case 4:
				system("cls");
				//pat=fopen("nizamiye_hospital.txt","r+");
				pat=fopen("nizamiye_hospital.txt","w");
				printf("enter the patients name..\n");
				scanf("%s",&patientname);
				printf("enter the patient surname..\n");
				scanf("%s",&patientsurname);

				//for(i=0;!feof(pat);i++)
				patient_was_found = 0;
				for(i=0;i<totalpatients;i++)
				{

					if(strcmp(patientname,patient[i].name)==0 && strcmp(patient[i].surname,patientsurname)==0)
					{
						printf("1.change status to admitted\n2.change status to discharged\n");
						scanf("%d",&statuschange);
						if(statuschange==1)
						{
							strcpy(patient[i].status,"admitted");
							printf("The status of %s %s has sucessfully been changed to %s\n",patientname,patientsurname,patient[i].status);
							patient_was_found = 1;
							//fprintf(pat,"%s %s %s %d %s %d",patient[i].name,patient[i].surname,patient[i].gender,patient[i].age,patient[i].status,patient[i].id);
						}
						if(statuschange==2)
						{
							strcpy (patient[i].status,"discharged");
							printf("the status of %s %s has successfully been changed to %s\n",patientname,patientsurname,patient[i].status);
							patient_was_found = 1;
						//fprintf(pat,"%s %s %s %d %s %d",&patient[i].name,&patient[i].surname,&patient[i].gender,&patient[i].age,&patient[i].status,&patient[i].id);
						}
					}
					//else if(feof(pat) && strcmp(patientname,patient[i].name)!=0 && strcmp(patient[i].surname,patientsurname)!=0)
					else if(i==totalpatients-1 && patient_was_found == 0)
					{
						printf("the name was not found\n");
					}
					fprintf(pat,"%s %s %s %d %s %d\n",patient[i].name,patient[i].surname,patient[i].gender,patient[i].age,patient[i].status,patient[i].id);

				}

				fclose(pat);
				break;
				case 5:
				//while(con==2)
				//{
					system("cls");
					int i,ask;
					int go;
					//pat=fopen("nizamiye_hospital.txt","r");
					printf("1.filter all male gender\n2.filter all female\n");
					printf("enter your filter choice\n");
					scanf("%d",&ask);
					printf("the  patient's details are as follow\n");
					printf("Name.. Lastname.. Gender.. Age.. Status.. Id..\n");
					//for (i=0;!feof(pat);i++)
					for (i=0;i<totalpatients;i++)
					{
						//fscanf(pat,"%s %s %s %d %s %d",&patient[i].name,&patient[i].surname,&patient[i].gender,&patient[i].age,&patient[i].status,&patient[i].id);
						if(ask==1 && strcmp(patient[i].gender,"male")==0)
						{
							printf("%s %s %s %d %s %d\n",patient[i].name,patient[i].surname,patient[i].gender,patient[i].age,patient[i].status,patient[i].id);
						}
						else if(ask==2 && strcmp(patient[i].gender,"female")==0)
						{
							printf("%s %s %s %d %s %d\n",patient[i].name,patient[i].surname,patient[i].gender,patient[i].age,patient[i].status,patient[i].id);
						}
					}
					break;

						//fclose(pat);

			case 6:
				printf("Closing...");
				return 0;

	        default:
	        	system("cls");
	        	printf("no such menu_choice exists");
	        	//system("cls");
	        	break;

		}

		printf("do you wish to continue?\n1.Y\n2.N\n");
		scanf("%d",&cont);
		if (cont==1)
		{
			count=1;
		}
		else
		{
			count=0;
		}




  }
	while(count==1);
	return 0;
}
int nextid(int* idno)
{
	return ++(*idno);
}



