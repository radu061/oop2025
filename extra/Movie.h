class Movie
{
	private:
		char *name;
		int year;
		int length;
		double IMDB;
	public:
		void set_name(const char* nou);
		const char* get_name();
		int get_year();
		void set_year(int x);
		double get_IMDB();
		void set_IMDB(double IMDBnou);
		int get_length();
		void set_length(int lg);
		int passyear();
};

