class Singleton {

	private static Singleton instance;
	private String data;
	
	private Singleton(String data) {
		this.data = data;
	}

	public static Singleton getInstance(String data) {
		if(instance == null) {
			instance = new Singleton(data);
		} 
		return instance;
	}

	@Override
	public String toString() {
		return "Singleton(data="+this.data+")";
	}
	
	public static void log(Object o) {
		System.out.println(o);
	}

	public static void main(String[] args) {
		Singleton s = Singleton.getInstance("new instance");
		log(s);
	}
};

