let dados = [];
let categoria = 0;
const hoje = new Date();

async function carregarDados() {
    try {
        const resposta = await fetch('http://localhost:3000/eventos');
        if (!resposta.ok) {
            throw new Error('Erro ao buscar os dados: ' + resposta.statusText);
        }

        dados = await resposta.json();

        carregarDestaques();
        carregarCards();

        const params = new URLSearchParams(window.location.search);
        const id = parseInt(params.get('id'));
        if (!isNaN(id)) {
            getEvento(id);
        }

        const pesquisa = document.getElementById('searchInput');
        if (pesquisa) {
            pesquisa.addEventListener('keypress', function (e) {
                if (e.key === 'Enter') {
                    const resultado = document.getElementById("resultadoPesquisa");
                    const searchValue = e.target.value.trim().toLowerCase();

                    const eventosFiltrados = dados.filter(item =>
                        item.titulo.toLowerCase().includes(searchValue)
                    );

                    resultado.innerHTML = '';

                    eventosFiltrados.slice(0, 3).forEach(evento => {
                        resultado.innerHTML += `
                            <a class="searchResult" href="detalhes.html?id=${evento.id}">
                                <div class="row">
                                    <div class="col">
                                        <img src="${evento.banner}" style="width: 150px; border-radius: 15px; max-height: 90px;" alt="">
                                    </div>
                                    <div class="col">
                                        <p>${evento.titulo}</p>
                                    </div>
                                </div>
                            </a>`;
                    });

                    if (eventosFiltrados.length === 0) {
                        resultado.innerHTML = '<p>Nenhum resultado encontrado.</p>';
                    }
                }
            });
        }

    } catch (erro) {
        console.error("Erro ao carregar dados:", erro);
    }
}

function parseDataHoraBrasileira(str) {
    const [data, hora] = str.split(" ");
    const [dia, mes, ano] = data.split("/");
    const [horas, minutos] = hora.split(":");
    return new Date(ano, mes - 1, dia, horas, minutos);
}

function gerarCard(evento) {
    const partes = evento.dataInicio.split(" ");
    const data = partes[0].split("/").reverse().join("-");
    const hora = partes[1];
    const dataHoraInicio = new Date(`${data}T${hora}:00`);

    const agora = new Date();
    let classeData = " dataNormal";
    if (dataHoraInicio < agora) {
        classeData = " dataPassada";
    }
    return `<a class="col-12 col-md-6 col-lg-3 mb-3" href="detalhes.html?id=${evento.id}">
                <div class="card cardEvento">
                    <img src="${evento.banner}" class="card-img-top" alt="${evento.nome}">
                    <div class="card-body">
                        <h5 class="card-title">${evento.titulo}</h5>
                        <p class="card-text">${evento.endereco}</p>
                        <p class="card-text${classeData}">${evento.dataInicio} - ${evento.dataFim}</p>
                    </div>
                </div>
            </a>`;
}

function setCategoria(id) {
    categoria = id;
    carregarCards();
}

function carregarDestaques() {
    const conteudo = document.getElementById("carouselConteudo");
    const botoes = document.getElementById("carouselButtons");
    if (conteudo) {
        let status = true;
        let contador = 0;
        dados.forEach(element => {
            if (element.destaque) {
                const classe = status ? "carousel-item active" : "carousel-item";
                const classeBotao = status ? "class='active' aria-current='true'" : "";
                status = false;

                conteudo.innerHTML += `
                    <div class="${classe}">
                        <img src="${element.banner}" class="d-block w-100" alt="...">
                        <div class="carousel-caption d-none d-md-block">
                            <h5>${element.titulo}</h5>
                            <p>${element.descricaoBreve}</p>
                        </div>
                    </div>`;
                botoes.innerHTML += `<button type="button" data-bs-target="#carouselExampleCaptions" data-bs-slide-to="${contador}"
                            ${classeBotao} aria-label="Slide ${contador}"></button>`;
                contador++;
            }
        });
    }
}

function carregarCards() {
    const cardsTodos = document.getElementById("cardsTodos");
    const cardsProximos = document.getElementById("cardsProximos");

    if (cardsTodos && cardsProximos) {
        cardsTodos.innerHTML = "";
        cardsProximos.innerHTML = "";
    }

    let temEventos = false;
    let temEventosProximos = false;

    dados.forEach(evento => {
        if (categoria != 0 && categoria == evento.categoria) {
            gerar();
        } else if (categoria == 0) {
            gerar();
        }

        function gerar() {
            const cardHTML = gerarCard(evento);

            if (cardsTodos) {
                cardsTodos.innerHTML += cardHTML;
                temEventos = true;
            }

            const dataInicio = parseDataHoraBrasileira(evento.dataInicio);
            const diffEmDias = (dataInicio - hoje) / (1000 * 60 * 60 * 24);

            if (diffEmDias >= 0 && diffEmDias <= 7 && cardsProximos) {
                cardsProximos.innerHTML += cardHTML;
                temEventosProximos = true;
            }
        }
    });

    if (!temEventos && cardsTodos) {
        cardsTodos.innerHTML = `<div class="alert alert-secondary" role="alert">
        Nenhum evento disponível no momento.
      </div>`;
    }

    if (!temEventosProximos && cardsProximos) {
        cardsProximos.innerHTML = `<div class="alert alert-secondary" role="alert">
        Não há eventos nos próximos 7 dias.
      </div>`;
    }
}

function getEvento(id) {
    carregarImagensComplementares(id);
    const evento = dados.find(item => item.id == id);
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
    if (bannerDetalhes && evento) {
        bannerDetalhes.style.backgroundImage = "url('" + evento.banner + "')";
    }
    if (imagemEvento && evento) {
        imagemEvento.innerHTML = `<img src="${evento.banner}" class="img-fluid rounded shadow">`;
    }
    if (enderecoEvento && evento) {
        enderecoEvento.innerHTML += `<svg xmlns="http://www.w3.org/2000/svg" class="svg16" fill="#9b5bbf"
                                    class="bi bi-geo-fill" viewBox="0 0 16 16">
                                    <path fill-rule="evenodd"
                                        d="M4 4a4 4 0 1 1 4.5 3.969V13.5a.5.5 0 0 1-1 0V7.97A4 4 0 0 1 4 3.999zm2.493 8.574a.5.5 0 0 1-.411.575c-.712.118-1.28.295-1.655.493a1.3 1.3 0 0 0-.37.265.3.3 0 0 0-.057.09V14l.002.008.016.033a.6.6 0 0 0 .145.15c.165.13.435.27.813.395.751.25 1.82.414 3.024.414s2.273-.163 3.024-.414c.378-.126.648-.265.813-.395a.6.6 0 0 0 .146-.15l.015-.033L12 14v-.004a.3.3 0 0 0-.057-.09 1.3 1.3 0 0 0-.37-.264c-.376-.198-.943-.375-1.655-.493a.5.5 0 1 1 .164-.986c.77.127 1.452.328 1.957.594C12.5 13 13 13.4 13 14c0 .426-.26.752-.544.977-.29.228-.68.413-1.116.558-.878.293-2.059.465-3.34.465s-2.462-.172-3.34-.465c-.436-.145-.826-.33-1.116-.558C3.26 14.752 3 14.426 3 14c0-.599.5-1 .961-1.243.505-.266 1.187-.467 1.957-.594a.5.5 0 0 1 .575.411" />
                                </svg> ${evento.endereco}
                                <br>
                                <svg xmlns="http://www.w3.org/2000/svg" class="svg16" fill="#f1596d"
                                    class="bi bi-calendar-week" viewBox="0 0 16 16">
                                    <path
                                        d="M11 6.5a.5.5 0 0 1 .5-.5h1a.5.5 0 0 1 .5.5v1a.5.5 0 0 1-.5.5h-1a.5.5 0 0 1-.5-.5zm-3 0a.5.5 0 0 1 .5-.5h1a.5.5 0 0 1 .5.5v1a.5.5 0 0 1-.5.5h-1a.5.5 0 0 1-.5-.5zm-5 3a.5.5 0 0 1 .5-.5h1a.5.5 0 0 1 .5.5v1a.5.5 0 0 1-.5.5h-1a.5.5 0 0 1-.5-.5zm3 0a.5.5 0 0 1 .5-.5h1a.5.5 0 0 1 .5.5v1a.5.5 0 0 1-.5.5h-1a.5.5 0 0 1-.5-.5z" />
                                    <path
                                        d="M3.5 0a.5.5 0 0 1 .5.5V1h8V.5a.5.5 0 0 1 1 0V1h1a2 2 0 0 1 2 2v11a2 2 0 0 1-2 2H2a2 2 0 0 1-2-2V3a2 2 0 0 1 2-2h1V.5a.5.5 0 0 1 .5-.5M1 4v10a1 1 0 0 0 1 1h12a1 1 0 0 0 1-1V4z" />
                                </svg> ${evento.dataInicio} -> ${evento.dataFim}`;
    }

    if (valorEvento && evento) {
        valorEvento.innerText = `Valor do Ingresso: R$${evento.preco}`;
    }
}

function carregarImagensComplementares(id) {
    const conteudo = document.getElementById("imagensComplementares");
    if (conteudo) {
        dados.forEach(evento => {
            if (evento.id == id && evento.imagens_complementares) {
                evento.imagens_complementares.forEach(element => {
                    conteudo.innerHTML += `<div class="col complementarGrupo"><img class="imagemComplementar" src="${element.src}"></div>`;
                });
            }
        });
    }
}

carregarDados();
