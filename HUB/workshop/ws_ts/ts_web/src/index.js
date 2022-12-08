/*
** Class
*/
var __awaiter = (this && this.__awaiter) || function (thisArg, _arguments, P, generator) {
    function adopt(value) { return value instanceof P ? value : new P(function (resolve) { resolve(value); }); }
    return new (P || (P = Promise))(function (resolve, reject) {
        function fulfilled(value) { try { step(generator.next(value)); } catch (e) { reject(e); } }
        function rejected(value) { try { step(generator["throw"](value)); } catch (e) { reject(e); } }
        function step(result) { result.done ? resolve(result.value) : adopt(result.value).then(fulfilled, rejected); }
        step((generator = generator.apply(thisArg, _arguments || [])).next());
    });
};
var __generator = (this && this.__generator) || function (thisArg, body) {
    var _ = { label: 0, sent: function() { if (t[0] & 1) throw t[1]; return t[1]; }, trys: [], ops: [] }, f, y, t, g;
    return g = { next: verb(0), "throw": verb(1), "return": verb(2) }, typeof Symbol === "function" && (g[Symbol.iterator] = function() { return this; }), g;
    function verb(n) { return function (v) { return step([n, v]); }; }
    function step(op) {
        if (f) throw new TypeError("Generator is already executing.");
        while (g && (g = 0, op[0] && (_ = 0)), _) try {
            if (f = 1, y && (t = op[0] & 2 ? y["return"] : op[0] ? y["throw"] || ((t = y["return"]) && t.call(y), 0) : y.next) && !(t = t.call(y, op[1])).done) return t;
            if (y = 0, t) op = [op[0] & 2, t.value];
            switch (op[0]) {
                case 0: case 1: t = op; break;
                case 4: _.label++; return { value: op[1], done: false };
                case 5: _.label++; y = op[1]; op = [0]; continue;
                case 7: op = _.ops.pop(); _.trys.pop(); continue;
                default:
                    if (!(t = _.trys, t = t.length > 0 && t[t.length - 1]) && (op[0] === 6 || op[0] === 2)) { _ = 0; continue; }
                    if (op[0] === 3 && (!t || (op[1] > t[0] && op[1] < t[3]))) { _.label = op[1]; break; }
                    if (op[0] === 6 && _.label < t[1]) { _.label = t[1]; t = op; break; }
                    if (t && _.label < t[2]) { _.label = t[2]; _.ops.push(op); break; }
                    if (t[2]) _.ops.pop();
                    _.trys.pop(); continue;
            }
            op = body.call(thisArg, _);
        } catch (e) { op = [6, e]; y = 0; } finally { f = t = 0; }
        if (op[0] & 5) throw op[1]; return { value: op[0] ? op[1] : void 0, done: true };
    }
};
var _this = this;
;
/*
** variables
*/
var container = document.getElementById("container");
var spinner = document.getElementById("spinner");
var pokemonNumber = 100;
var pokemonList = [];
/*
** Core
*/
var getPokemon = function (id) { return __awaiter(_this, void 0, void 0, function () {
    var pokemon;
    return __generator(this, function (_a) {
        switch (_a.label) {
            case 0: return [4 /*yield*/, fetch("https://pokeapi.co/api/v2/pokemon/".concat(id)).then(function (res) { return res.json(); })];
            case 1:
                pokemon = _a.sent();
                console.log(pokemon);
                return [2 /*return*/];
        }
    });
}); };
var showSpinner = function () {
    container.style.display = "none";
    spinner.style.display = "inline-block";
};
var hideSpinner = function () {
    spinner.style.display = "none";
    container.style.display = "block";
};
var showPokemon = function (pokemon) {
    var element = "\n        <div class=\"card\">\n            <span class=\"card-id\">#".concat(pokemon.id, "</span>\n            <img class=\"card-image\" src=").concat(pokemon.imageSrc, " alt=").concat(pokemon.name, " />\n            <h2 class=\"card-name\">").concat(pokemon.name, "</h2>\n            <span class=\"card-details\">").concat(pokemon.type, "</span>\n        </div>\n    ");
    container.innerHTML += element;
};
(function () { return __awaiter(_this, void 0, void 0, function () {
    var i;
    return __generator(this, function (_a) {
        switch (_a.label) {
            case 0:
                showSpinner();
                i = 0;
                _a.label = 1;
            case 1:
                if (!(i < pokemonNumber)) return [3 /*break*/, 4];
                return [4 /*yield*/, getPokemon(i)];
            case 2:
                _a.sent();
                _a.label = 3;
            case 3:
                i++;
                return [3 /*break*/, 1];
            case 4:
                hideSpinner();
                return [2 /*return*/];
        }
    });
}); })();
