# bs-fetcher

Mashup of [`bs-fetch`](https://github.com/reasonml-community/bs-fetch) and [`bs-node-fetch`](https://github.com/arnarthor/bs-node-fetch)

**All credit goes to those @glennsl and @arnarthor, see those repos for details.**

## BsNodeFetch

[`BsNodeFetch.re`](./src/BsNodeFetch.re) corresponds with the [`bs-node-fetch`](https://github.com/arnarthor/bs-node-fetch) master branch.

## Fetch

[`Fetch.re`](./src/Fetch.re) corresponds with the [`bs-fetch`](https://github.com/reasonml-community/bs-fetch/) master branch.

## FetchNext

[`FetchNext.re`](./src/FetchNext.re) corresponds with the [`bs-fetch-next`](https://github.com/reasonml-community/bs-fetch/tree/next) branch on [`bs-fetch`](https://github.com/reasonml-community/bs-fetch).

`bs-fetch` is intended as a thin layer atop the JS API, upon which more high-level and idiomatic libraries can be made. Once such a library has been established, these bindings will likely be refactored to be even thinner.

## Running Examples with Node.js polyfill

[`bs-fetch`](https://github.com/reasonml-community/bs-fetch) has a section explaining how to use that project on the server using [`isomorphic-fetch`](https://github.com/matthew-andrews/isomorphic-fetch).

## Example

```reason
Js.Promise.(
  Fetch.fetch("https://dog.ceo/api/breeds/image/random/5")
  |> then_(Fetch.Response.text)
  |> then_(text => print_endline(text) |> resolve)
);
```

## Installation

```sh
npm install --save bs-fetcher
```

Then add `bs-fetcher` to `bs-dependencies` in your `bsconfig.json`:

```json
{
  ...
  "bs-dependencies": ["bs-fetcher"]
}
```

## `method_` or `_method`

Converting the `bs-fetch` files to reason only seem to work if you use `_method` signature to deal with the resevered `method` keyword in bucklescript. In `OCaml` syntax, `method_` works.
