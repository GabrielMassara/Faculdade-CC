package app;

import java.util.List;
import java.util.Scanner;

import dao.UsuarioDAO;
import model.Usuario;

public class Aplicacao {
	
	private static UsuarioDAO usuarioDAO = new UsuarioDAO();
	private static Scanner scanner = new Scanner(System.in);
	
	public static void main(String[] args) throws Exception {
		int opcao = 0;
		
		do {
			mostrarMenu();
			System.out.print("Escolha uma opção: ");
			opcao = scanner.nextInt();
			scanner.nextLine();
			
			switch(opcao) {
				case 1:
					listarUsuarios();
					break;
				case 2:
					inserirUsuario();
					break;
				case 3:
					excluirUsuario();
					break;
				case 4:
					atualizarUsuario();
					break;
				case 5:
					System.out.println("Saindo...");
					break;
				default:
					System.out.println("Opção inválida!");
			}
			
			if(opcao != 5) {
				System.out.println("\nPressione Enter para continuar...");
				scanner.nextLine();
			}
			
		} while(opcao != 5);
		
		scanner.close();
	}
	
	private static void mostrarMenu() {
		System.out.println("\n===== SISTEMA DE USUÁRIOS =====");
		System.out.println("1. Listar usuários");
		System.out.println("2. Inserir usuário");
		System.out.println("3. Excluir usuário");
		System.out.println("4. Atualizar usuário");
		System.out.println("5. Sair");
		System.out.println("================================");
	}
	
	private static void listarUsuarios() {
		System.out.println("\n==== LISTA DE USUÁRIOS ====");
		List<Usuario> usuarios = usuarioDAO.getOrderByCodigo();
		
		if(usuarios.isEmpty()) {
			System.out.println("Nenhum usuário encontrado.");
		} else {
			System.out.println("Código | Login | Senha | Sexo");
			System.out.println("----------------------------");
			for (Usuario u: usuarios) {
				System.out.println(u.toString());
			}
		}
	}
	
	private static void inserirUsuario() {
		System.out.println("\n==== INSERIR USUÁRIO ====");
		
		System.out.print("Código: ");
		int codigo = scanner.nextInt();
		scanner.nextLine();
		
		System.out.print("Login: ");
		String login = scanner.nextLine();
		
		System.out.print("Senha: ");
		String senha = scanner.nextLine();
		
		System.out.print("Sexo (M/F): ");
		char sexo = scanner.nextLine().toUpperCase().charAt(0);
		
		Usuario usuario = new Usuario(codigo, login, senha, sexo);
		
		if(usuarioDAO.insert(usuario)) {
			System.out.println("Usuário inserido com sucesso!");
		} else {
			System.out.println("Erro ao inserir usuário.");
		}
	}
	
	private static void excluirUsuario() {
		System.out.println("\n==== EXCLUIR USUÁRIO ====");
		
		listarUsuarios();
		
		System.out.print("\nDigite o código do usuário a ser excluído: ");
		int codigo = scanner.nextInt();
		
		if(usuarioDAO.delete(codigo)) {
			System.out.println("Usuário excluído com sucesso!");
		} else {
			System.out.println("Erro ao excluir usuário ou usuário não encontrado.");
		}
	}
	
	private static void atualizarUsuario() {
		System.out.println("\n==== ATUALIZAR USUÁRIO ====");
		
		listarUsuarios();
		
		System.out.print("\nDigite o código do usuário a ser atualizado: ");
		int codigo = scanner.nextInt();
		scanner.nextLine();
		
		Usuario usuario = usuarioDAO.get(codigo);
		if(usuario == null) {
			System.out.println("Usuário não encontrado.");
			return;
		}
		
		System.out.println("Usuário atual: " + usuario.toString());
		System.out.println("\nDeixe em branco para manter o valor atual:");
		
		System.out.print("Novo login (" + usuario.getLogin() + "): ");
		String novoLogin = scanner.nextLine();
		if(!novoLogin.trim().isEmpty()) {
			usuario.setLogin(novoLogin);
		}
		
		System.out.print("Nova senha: ");
		String novaSenha = scanner.nextLine();
		if(!novaSenha.trim().isEmpty()) {
			usuario.setSenha(novaSenha);
		}
		
		System.out.print("Novo sexo (" + usuario.getSexo() + ") (M/F): ");
		String novoSexoStr = scanner.nextLine();
		if(!novoSexoStr.trim().isEmpty()) {
			char novoSexo = novoSexoStr.toUpperCase().charAt(0);
			usuario.setSexo(novoSexo);
		}
		
		if(usuarioDAO.update(usuario)) {
			System.out.println("Usuário atualizado com sucesso!");
		} else {
			System.out.println("Erro ao atualizar usuário.");
		}
	}
}