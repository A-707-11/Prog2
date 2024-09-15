#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "patient.h"

#define MAX 5

void registerPatient(patient_type* patient_ptr);
void viewPatientRecord(patient_type patient_rec);
patient_type* transferPatientRecord(patient_type patient_rec);
bool checkMandatoryFields(patient_type patient_rec, bool isAdmittedFlag);
void acceptOutPatients(patient_type outpat_ward[]);
void viewOutPatients(patient_type outpat_ward[]);
void seggregatePatients(patient_type outpat_ward[], patient_type general_ward[], patient_type pedia_ward[], patient_type obgyne_ward[], patient_type rehab_ward[]);
void line();

int main()
{
	patient_type outpat_ward[MAX];
	patient_type general_ward[MAX];
	patient_type pedia_ward[MAX];
	patient_type obgyne_ward[MAX];
	patient_type rehab_ward[MAX];
	
	patient_type patient1;
	
//	registerPatient(&patient1);
//	checkMandatoryFields(patient1, true);
//	line();
//	viewPatientRecord(patient1);
//	line();
//	patient_type *patient = transferPatientRecord(patient1);
//	viewPatientRecord(*patient);
//	line();
	acceptOutPatients(outpat_ward);
	viewOutPatients(outpat_ward);
	seggregatePatients(outpat_ward, general_ward, pedia_ward, obgyne_ward, rehab_ward);
	printf("\n\nGENERAL WARD\n\n");
	viewOutPatients(rehab_ward);
}

void registerPatient(patient_type* patient_ptr)
{
	int i;
	
	//ID
	patient_ptr->patient_id = 0;
	printf("Enter ID: ");
	scanf("%d", &patient_ptr->patient_id);
	fflush(stdin);
	
	//NAME
	printf("\nEnter Full Name: \n\n");
	printf("  Enter First Name: ");
	gets(patient_ptr->name.first);
	printf(" Enter Middle Name: ");
	gets(patient_ptr->name.middle);
	printf("   Enter Last Name: "); 
	gets(patient_ptr->name.last);
	
	//BIRTHDAY
	printf("\nEnter Birthday(mm/dd/yyyy): ");
	scanf("%d %d %d", &patient_ptr->bdate.month, &patient_ptr->bdate.day, &patient_ptr->bdate.year);
	fflush(stdin);
	
	//GENDER
	printf("                    Gender: ");
	scanf("%c", &patient_ptr->gender);
	fflush(stdin);
	
	//CIVIL STATUS
	printf("              Civil Status: ");
	scanf("%c", &patient_ptr->civil_status);
	fflush(stdin);
	
	//ADDRESS
	printf("\nEnter Address: \n\n");
	printf("  Street: ");
	gets(patient_ptr->address.street);
	printf("Barangay: ");
	gets(patient_ptr->address.brgy);
	printf("    City: "); 
	gets(patient_ptr->address.city);
	printf("Zip Code: "); 
	scanf("%d", &patient_ptr->address.zip_code);
	fflush(stdin);
	
	//EMERGENCY CONTACT
	printf("\nEnter Emergency Contact: \n\n");
	printf("          Enter Contact Name: ");
	gets(patient_ptr->em_cont.name);
	printf(" Enter Contact Mobile Number: ");
	gets(patient_ptr->em_cont.mobile);
	printf("    Enter Last Name Relation: "); 
	gets(patient_ptr->em_cont.relation);
	printf("\n");
	
	//HEIGHT
	printf("Enter Height: ");
	scanf("%f", &patient_ptr->height);
	fflush(stdin);
	//WEIGHT
	printf("Enter Weight: ");
	scanf("%f", &patient_ptr->weight);
	fflush(stdin);
	
	//PATIENT CHART
	printf("   Diagnosis: ");
	gets(patient_ptr->pat_chart.diagnosis);
	printf("   Treatment: ");
	gets(patient_ptr->pat_chart.treatment);
	printf(" Ward Number: ");
	scanf("%d", &patient_ptr->pat_chart.ward_no);
	fflush(stdin);
	printf("   Doctor ID: \n\n");
	for(i = 0; i < 5 ; i++)
	{
		printf("ID[%d]: ", i);
		scanf("%d", &patient_ptr->pat_chart.doc_id[i]);
		fflush(stdin);
	}
	printf("\n\n");
}

void viewPatientRecord(patient_type patient_rec)
{
	int i;
	printf("\n\t----|PATIENT DETAILS|----\n");
	printf("                    ID: %d\n", patient_rec.patient_id);
	printf("                  Name: %s %s %s\n", patient_rec.name.first, patient_rec.name.middle, patient_rec.name.last);
	printf("              Birthday: %d/%d/%d\n", patient_rec.bdate.month, patient_rec.bdate.day, patient_rec.bdate.year);
	printf("                Gender: %c\n", patient_rec.gender);
	printf("           CivilStatus: %c\n", patient_rec.civil_status);
	printf("               Address: %s, %s, %s, %d\n", patient_rec.address.street, patient_rec.address.brgy, patient_rec.address.city, patient_rec.address.zip_code);
	printf("                Height: %.2f\n", patient_rec.height);
	printf("                Weight: %.2f\n", patient_rec.weight);
	printf("\t----|PATIENT CHART|----\n");
	printf("             Diagnosis: %s\n", patient_rec.pat_chart.diagnosis);
	printf("             Treatment: %s\n", patient_rec.pat_chart.treatment);
	printf("           Ward Number: %d\n", patient_rec.pat_chart.ward_no);
	for(i = 0; i < 5; i++)
	{
		printf("            Doctor[%d]: %d\n", i, patient_rec.pat_chart.doc_id[i]);
	}
	printf("\t----|EMERGENCY CONTACT|----\n");
	printf("        Emergency Name: %s\n", patient_rec.em_cont.name);
	printf("     Emergency Contact: %s\n", patient_rec.em_cont.mobile);
	printf("Emergency Relationship: %s\n", patient_rec.em_cont.relation);
}

patient_type* transferPatientRecord(patient_type patient_rec)
{
	int ward;
	patient_type* new_rec = (patient_type*)malloc(sizeof(patient_type));
	
	printf("Select New Patient Ward: \n");
	scanf("%d", &patient_rec.pat_chart.ward_no);
	*new_rec = patient_rec;
	return new_rec;
}

bool checkMandatoryFields(patient_type patient_rec, bool isAdmittedFlag)
{
	int check = 0;
	if(isAdmittedFlag)
	{
		if(patient_rec.patient_id == 0)
		{
			printf("ID is blank!");
			check++;	
		}
		else if(patient_rec.name.first[0] == 0 ||patient_rec.name.middle[0] == 0 || patient_rec.name.last[0] == 0 )
		{
			printf("Enter Full Name!");
			check++;	
		}
		else if (patient_rec.bdate.month == 0 || patient_rec.bdate.day == 0 || patient_rec.bdate.year == 0)
		{
			printf("Invalid Birthday!");
			check++;
		}
		else if (patient_rec.gender == 0)
		{
			printf("Gender is Blank!");
			check++;
		}
		else if (patient_rec.civil_status == 0)
		{
			printf("Gender is Blank!");
			check++;
		}
		else if (patient_rec.address.street[0] == 0 || patient_rec.address.brgy[0] == 0 || patient_rec.address.city[0] == 0 || patient_rec.address.zip_code == 0 )
		{
			printf("Incomplete Address!");
			check++;
		}
		else if (patient_rec.em_cont.name[0] == 0 || patient_rec.em_cont.relation[0] == 0 || patient_rec.em_cont.mobile[0] == 0)
		{
			printf("Incomplete Emergency Contact!");
			check++;
		}
		else if (patient_rec.height == 0)
		{
			printf("Height is blank!");
			check++;
		}
		else if (patient_rec.weight == 0)
		{
			printf("Weight is blank!");
			check++;
		}				
	}
	else
	{
		if (patient_rec.pat_chart.diagnosis[0] == 0|| patient_rec.pat_chart.treatment[0] == 0 || patient_rec.pat_chart.ward_no == 0 || patient_rec.pat_chart.doc_id[0] == 0)
		{
			printf("Patient Chart is Incomplete!");
			check++;
		}	
	}
	
	if(check > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}

void acceptOutPatients(patient_type outpat_ward[])
{
	int i;
	
	for(i = 0; i < 3 ; i++)
	{
		line();
		printf("Enter Patient[%d]: \n\n", i);
		registerPatient(&outpat_ward[i]);
	}
}

void viewOutPatients(patient_type outpat_ward[])
{
	int i;
	
	for(i = 0; i < MAX ; i++)
	{
		line();
		printf("\n\nPatient[%d]: \n\n", i);
		viewPatientRecord(outpat_ward[i]);
	}
}

void seggregatePatients(patient_type outpat_ward[], patient_type general_ward[], patient_type pedia_ward[], patient_type obgyne_ward[], patient_type rehab_ward[])
{
	int i;
	for(i = 0; i < MAX; i++)
	{
		if (strcmp(outpat_ward[i].pat_chart.diagnosis, "burns") == 0 || strcmp(outpat_ward[i].pat_chart.diagnosis, "fractures") == 0 || strcmp(outpat_ward[i].pat_chart.diagnosis, "injury") == 0)
		{
			rehab_ward[i] = outpat_ward[i];
		}
	}
}	


void line(){
	printf("\n\n------------------------------------------------\n\n");
}








