const dados = [
    {
        "id": 1,
        "titulo": "BH STOCK FESTIVAL 2025",
        "descricao": "Vem com a gente, porque o futuro já está no horizonte, e o BH Stock Festival será sua próxima conquista! 🏁",
        "descricaoBreve": "...",
        "cidade": 0,
        "endereco": "Av. Antônio Abrahão Caram, 1001 - Esplanada Norte - São José",
        "dataInicio": "15/08/2025 08:00",
        "dataFim": "17/08/2025 23:59",
        "preco": 200,
        "quantidadeIngressos": 500,
        "banner": "img/banners/1.png",
        "categoria": 1,
        "contadorClick": 0
    },
    {
        "id": 2,
        "titulo": "CARNACHALÉ 17 ANOS",
        "descricao": "Evento de comemoração dos 17 anos do CARNACHALÉ",
        "descricaoBreve": "...",
        "cidade": 0,
        "endereco": "Av. Professor Mário Werneck, 530, Belo Horizonte - MG",
        "dataInicio": "12/04/2025 13:00",
        "dataFim": "13/04/2025 06:00",
        "preco": 200,
        "quantidadeIngressos": 500,
        "banner": "img/banners/2.png",
        "categoria": 1,
        "contadorClick": 0
    },
    {
        "id": 3,
        "titulo": "House Paradise 9 Anos | Vintage Culture",
        "descricao": "Dia 30 de Abril de 2025, vamos reviver fortes emoções e celebrar juntos tudo nos uniu até aqui. Nosso Special Guest VINTAGE CULTURE, um dos artistas mais aclamados de todos os tempos! E mais Departamento, Doozie, Meca e outros artistas que estão por vir!",
        "descricaoBreve": "...",
        "cidade": 0,
        "endereco": "Parque de Exposições de Divinópolis, Divinópolis - MG",
        "dataInicio": "30/04/2025 22:00",
        "dataFim": "01/05/2025 10:00",
        "preco": 105,
        "quantidadeIngressos": 500,
        "banner": "img/banners/3.png",
        "categoria": 1,
        "contadorClick": 0
    },
    {
        "id": 4,
        "titulo": "PROJETO X",
        "descricao": "A maior festa universitária das atléticas de BH",
        "descricaoBreve": "...",
        "cidade": 0,
        "endereco": "A definir",
        "dataInicio": "24/04/2025 21:00",
        "dataFim": "25/04/2025 06:00",
        "preco": 200,
        "quantidadeIngressos": 500,
        "banner": "img/banners/4.png",
        "categoria": 1,
        "contadorClick": 0
    },
    {
        "id": 5,
        "titulo": "DRIFT FESTIVAL - MEUTRACKMINHAVIDA",
        "descricao": "O mais democrático Track de Belo Horizonte terá uma edição inédita de DRIFT com várias atrações",
        "descricaoBreve": "...",
        "cidade": 0,
        "endereco": "MEGA SPACE",
        "dataInicio": "12/04/2025 10:00",
        "dataFim": "12/04/2025 17:00",
        "preco": 48.6,
        "quantidadeIngressos": 500,
        "banner": "img/banners/5.png",
        "categoria": 1,
        "contadorClick": 0
    },
];

function parseDataHoraBrasileira(str) {
    const [data, hora] = str.split(" ");
    const [dia, mes, ano] = data.split("/");
    const [horas, minutos] = hora.split(":");
    return new Date(ano, mes - 1, dia, horas, minutos);
}

function gerarCard(evento) {
    return `<a class="col-12 col-md-6 col-lg-3 mb-3" href="detalhes.html?id=`+evento.id+`">
                <div class="card cardEvento">
                    <img src="${evento.banner}" class="card-img-top" alt="${evento.nome}">
                    <div class="card-body">
                        <h5 class="card-title">${evento.titulo}</h5>
                        <p class="card-text">${evento.endereco}</p>
                        <p class="card-text">${evento.dataInicio} - ${evento.dataFim}</p>
                    </div>
                </div>
            </a>`;
}

const hoje = new Date();

dados.forEach(evento => {
    const cardHTML = gerarCard(evento);
    const cardsTodos = document.getElementById("cardsTodos");
    const cardsProximos = document.getElementById("cardsProximos");

    if (cardsTodos) {
        cardsTodos.innerHTML += cardHTML;
    }

    const dataInicio = parseDataHoraBrasileira(evento.dataInicio);
    const diffEmDias = (dataInicio - hoje) / (1000 * 60 * 60 * 24);

    if (diffEmDias >= 0 && diffEmDias <= 7 && cardsProximos) {
        cardsProximos.innerHTML += cardHTML;
    }
});

const params = new URLSearchParams(window.location.search);
const id = parseInt(params.get('id'));

if (!isNaN(id)) {
    getEvento(id);
}

function getEvento(id) {
    const evento = dados.find(item => item.id === id);
    const tituloEvento = document.getElementById("tituloEvento");
    const imagemEvento = document.getElementById("imagemEvento");
    const descricaoEvento = document.getElementById("descricaoEvento");
    const descricaoBreveEvento = document.getElementById("descricaoBreveEvento");
    const valorEvento = document.getElementById("valorEvento");
    const enderecoEvento = document.getElementById("enderecoEvento");
    const bannerDetalhes = document.getElementById("bannerDetalhes");

    if (tituloEvento && evento) {
        tituloEvento.innerText = evento.titulo;
    }
    if (descricaoEvento && evento) {
        descricaoEvento.innerText = evento.descricao;
    }
    if (descricaoBreveEvento && evento) {
        descricaoBreveEvento.innerText = evento.descricaoBreve;
    }
    if(bannerDetalhes && evento) {
        bannerDetalhes.style.backgroundImage = "url('"+evento.banner+"')";
    }
    if (imagemEvento && evento) {
        imagemEvento.innerHTML = `<img src="` + evento.banner + `" class="img-fluid rounded shadow">`;
    }
    if (enderecoEvento && evento) {
        enderecoEvento.innerHTML += `<svg xmlns="http://www.w3.org/2000/svg" class="svg16" fill="#9b5bbf"
                                    class="bi bi-geo-fill" viewBox="0 0 16 16">
                                    <path fill-rule="evenodd"
                                        d="M4 4a4 4 0 1 1 4.5 3.969V13.5a.5.5 0 0 1-1 0V7.97A4 4 0 0 1 4 3.999zm2.493 8.574a.5.5 0 0 1-.411.575c-.712.118-1.28.295-1.655.493a1.3 1.3 0 0 0-.37.265.3.3 0 0 0-.057.09V14l.002.008.016.033a.6.6 0 0 0 .145.15c.165.13.435.27.813.395.751.25 1.82.414 3.024.414s2.273-.163 3.024-.414c.378-.126.648-.265.813-.395a.6.6 0 0 0 .146-.15l.015-.033L12 14v-.004a.3.3 0 0 0-.057-.09 1.3 1.3 0 0 0-.37-.264c-.376-.198-.943-.375-1.655-.493a.5.5 0 1 1 .164-.986c.77.127 1.452.328 1.957.594C12.5 13 13 13.4 13 14c0 .426-.26.752-.544.977-.29.228-.68.413-1.116.558-.878.293-2.059.465-3.34.465s-2.462-.172-3.34-.465c-.436-.145-.826-.33-1.116-.558C3.26 14.752 3 14.426 3 14c0-.599.5-1 .961-1.243.505-.266 1.187-.467 1.957-.594a.5.5 0 0 1 .575.411" />
                                </svg> `+ evento.endereco +
                `<br>
                                <svg xmlns="http://www.w3.org/2000/svg" class="svg16" fill="#f1596d"
                                    class="bi bi-calendar-week" viewBox="0 0 16 16">
                                    <path
                                        d="M11 6.5a.5.5 0 0 1 .5-.5h1a.5.5 0 0 1 .5.5v1a.5.5 0 0 1-.5.5h-1a.5.5 0 0 1-.5-.5zm-3 0a.5.5 0 0 1 .5-.5h1a.5.5 0 0 1 .5.5v1a.5.5 0 0 1-.5.5h-1a.5.5 0 0 1-.5-.5zm-5 3a.5.5 0 0 1 .5-.5h1a.5.5 0 0 1 .5.5v1a.5.5 0 0 1-.5.5h-1a.5.5 0 0 1-.5-.5zm3 0a.5.5 0 0 1 .5-.5h1a.5.5 0 0 1 .5.5v1a.5.5 0 0 1-.5.5h-1a.5.5 0 0 1-.5-.5z" />
                                    <path
                                        d="M3.5 0a.5.5 0 0 1 .5.5V1h8V.5a.5.5 0 0 1 1 0V1h1a2 2 0 0 1 2 2v11a2 2 0 0 1-2 2H2a2 2 0 0 1-2-2V3a2 2 0 0 1 2-2h1V.5a.5.5 0 0 1 .5-.5M1 4v10a1 1 0 0 0 1 1h12a1 1 0 0 0 1-1V4z" />
                                </svg> `+evento.dataInicio +" -> "+ evento.dataFim;
    }
    if (valorEvento && evento) {
        valorEvento.innerText = `Valor do Ingresso: R$${evento.preco}`;
    }
}

