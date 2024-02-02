// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// !!! unfinished implementation !!!
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

class Main {

	public static void log(Object o) {
		System.out.println(o);
	}

	public static void main(String[] args) {
		Singleton s = Singleton.getInstance("new instance");
		log(s);
	}

}
