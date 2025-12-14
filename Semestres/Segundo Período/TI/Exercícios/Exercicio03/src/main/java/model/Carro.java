package model;

public class Carro {
	private int id;
	private String modelo;
	private String marca;
	private int qtdLugares;
	
	public Carro() {
		id = -1;
		modelo = "";
		marca = "";
		qtdLugares = 0;
	}

	public Carro(int id, String modelo, String marca, int qtdLugares) {
		setId(id);
		setModelo(modelo);
		setMarca(marca);
		setQtdLugares(qtdLugares);
	}		
	
	public int getID() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
	}

	public String getModelo() {
		return modelo;
	}

	public void setModelo(String modelo) {
		this.modelo = modelo;
	}

	public String getMarca() {
		return marca;
	}

	public void setMarca(String marca) {
		this.marca = marca;
	}

	public int getQtdLugares() {
		return qtdLugares;
	}
	
	public void setQtdLugares(int qtdLugares) {
		this.qtdLugares = qtdLugares;
	}

	/**
	 * Método sobreposto da classe Object. É executado quando um objeto precisa
	 * ser exibido na forma de String.
	 */
	@Override
	public String toString() {
		return "Carro: " + modelo + " - Marca: " + marca + " - Lugares: " + qtdLugares;
	}
	
	@Override
	public boolean equals(Object obj) {
		return (this.getID() == ((Carro) obj).getID());
	}	
}