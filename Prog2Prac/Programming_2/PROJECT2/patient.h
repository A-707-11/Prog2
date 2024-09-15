
typedef struct {
	
	char last[20];
	char first[20];
	char middle[20];
	
}name_type;

typedef struct {
	
	int month;
	int day;
	int year;
	
}birth_type;

typedef struct {
	
	char name[20];
	char mobile[15];
	char relation[10];
	
}emergency_type;

typedef struct {
	
	char street[20];
	char brgy[10];
	char city[15];
	int zip_code;
	
}add_type;

typedef struct {
	
	char diagnosis[20];
	char treatment[20];
	int ward_no;
	int doc_id[5];
	
}chart_type;

typedef struct{
	
	int patient_id;
	name_type name;
	birth_type bdate;
	char gender; 
	char civil_status;
	add_type address;
	emergency_type em_cont;
	float height;
	float weight;
	chart_type pat_chart;
	
}patient_type;

