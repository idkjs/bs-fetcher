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

## Example

```reason
Js.Promise.(
  Fetch.fetch("/api/hellos/1")
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

## Usage

See usage examples in [`ocaml_examples.ml`](https://github.com/reasonml-community/bs-fetch/blob/master/examples/ocaml_examples.ml) and [`reason_examples.re`](https://github.com/reasonml-community/bs-fetch/blob/master/examples/reason_examples.re). The source is a [single file](https://github.com/reasonml-community/bs-fetch/blob/master/src/Fetch.ml)!

## Node.js polyfill

`fetch` is a Web API that isn't available out-of-the-box in Node.js, and will therefore need to be polyfilled. [isomorphic-fetch](https://github.com/matthew-andrews/isomorphic-fetch) one such polyfill that seems to work well. Just install it via npm and add `[%raw "require('isomorphic-fetch')"]` to the top of your main file, but be aware that there are some subtle differences and even parts that are missing entirely.

## Changes
