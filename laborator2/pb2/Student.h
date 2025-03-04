class Student
{
private:
	char name[105];
	float grade_math;
	float grade_eng;
	float grade_his;
public:
	void Init();
	void set_name(char new_name[]);
	void get_name(char destinatie[]);
	float get_math();
	bool set_math(float new_grade);
    float get_eng();
	bool set_eng(float new_grade);
	float get_his();
	bool set_his(float new_grade);
	float average();
};
