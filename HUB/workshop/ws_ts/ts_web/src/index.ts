/*
** Class
*/

interface IPokemon {
    id: number;
    name: string;
    imageSrc: string;
    shiny: string;
    type: string; 
};

/*
** variables
*/

const container: HTMLElement | any = document.getElementById("container");
const spinner: HTMLElement | any = document.getElementById("spinner");
const pokemonNumber: number = 151;
const pokemonList: IPokemon[] = [];

/*
** Core
*/

const getPokemon = async (id: number): Promise<void> => {
    const data = await fetch(`https://pokeapi.co/api/v2/pokemon/${id}`).then(res => res.json());
    // console.log(pokemon);
    const pokemon: IPokemon = {
        id,
        name: data.name,
        imageSrc: data.sprites.front_default,
        shiny: data.sprites.front_shiny,
        type: data.types.map((e: any) => e.type.name).join(',')
    };
    pokemonList.push(pokemon);
}

const showSpinner = (): void => {
    spinner.style.display = "flex";
    container.style.display = "none";
};

const hideSpinner = (): void => {
    spinner.style.display = "none";
    container.style.display = "grid";
};

const showPokemon = (pokemon: IPokemon): void => {
    const element: string = `
        <div class="card">
            <span class="card-id">#${pokemon.id}</span>
            <img class="card-image" src=${pokemon.imageSrc} alt=${pokemon.name} />
            <img class="card-image" src=${pokemon.shiny} alt=${pokemon.name} />
            <h2 class="card-name">${pokemon.name}</h2>
            <span class="card-details">${pokemon.type}</span>
        </div>
    `;
    container.innerHTML += element;
};

(async () => {
    showSpinner();
    for (let i: number = 1; i <= pokemonNumber; i++) {
        await getPokemon(i);
    }
    hideSpinner();
    pokemonList.forEach(pokemon => showPokemon(pokemon));
})();