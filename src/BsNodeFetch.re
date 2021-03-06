type body;

type bodyInit;

type headers;

type headersInit;

type response;

type request;

type requestInit;

/* external */
type arrayBuffer; /* TypedArray */

type blob; /* FileAPI */

type bufferSource; /* Web IDL, either an arrayBuffer or arrayBufferView */

type formData; /* XMLHttpRequest */

type readableStream; /* Streams */

type urlSearchParams; /* URL */

type requestMethod =
  | Get
  | Head
  | Post
  | Put
  | Delete
  | Connect
  | Options
  | Trace
  | Patch
  | Other(string);

let encodeRequestMethod =
  /* internal */
  fun
  | Get => "GET"
  | Head => "HEAD"
  | Post => "POST"
  | Put => "PUT"
  | Delete => "DELETE"
  | Connect => "CONNECT"
  | Options => "OPTIONS"
  | Trace => "TRACE"
  | Patch => "PATCH"
  | Other(method) => method;

let decodeRequestMethod =
  /* internal */
  fun
  | "GET" => Get
  | "HEAD" => Head
  | "POST" => Post
  | "PUT" => Put
  | "DELETE" => Delete
  | "CONNECT" => Connect
  | "OPTIONS" => Options
  | "TRACE" => Trace
  | "PATCH" => Patch
  | method => Other(method);

type referrerPolicy =
  | None
  | NoReferrer
  | NoReferrerWhenDowngrade
  | SameOrigin
  | Origin
  | StrictOrigin
  | OriginWhenCrossOrigin
  | StrictOriginWhenCrossOrigin
  | UnsafeUrl;

let encodeReferrerPolicy =
  /* internal */
  fun
  | None => ""
  | NoReferrer => "no-referrer"
  | NoReferrerWhenDowngrade => "no-referrer-when-downgrade"
  | SameOrigin => "same-origin"
  | Origin => "origin"
  | StrictOrigin => "strict-origin"
  | OriginWhenCrossOrigin => "origin-when-cross-origin"
  | StrictOriginWhenCrossOrigin => "strict-origin-when-cross-origin"
  | UnsafeUrl => "unsafe-url";

let decodeReferrerPolicy =
  /* internal */
  fun
  | "" => None
  | "no-referrer" => NoReferrer
  | "no-referrer-when-downgrade" => NoReferrerWhenDowngrade
  | "same-origin" => SameOrigin
  | "origin" => Origin
  | "strict-origin" => StrictOrigin
  | "origin-when-cross-origin" => OriginWhenCrossOrigin
  | "strict-origin-when-cross-origin" => StrictOriginWhenCrossOrigin
  | "unsafe-url" => UnsafeUrl
  | e => raise(Failure("Unknown referrerPolicy: " ++ e));

type requestType =
  | None /* default? unknown? just empty string in spec */
  | Audio
  | Font
  | Image
  | Script
  | Style
  | Track
  | Video;

let decodeRequestType =
  /* internal */
  fun
  | "" => None
  | "audio" => Audio
  | "font" => Font
  | "image" => Image
  | "script" => Script
  | "style" => Style
  | "track" => Track
  | "video" => Video
  | e => raise(Failure("Unknown requestType: " ++ e));

type requestDestination =
  | None /* default? unknown? just empty string in spec */
  | Document
  | Embed
  | Font
  | Image
  | Manifest
  | Media
  | Object
  | Report
  | Script
  | ServiceWorker
  | SharedWorker
  | Style
  | Worker
  | Xslt;

let decodeRequestDestination =
  /* internal */
  fun
  | "" => None
  | "document" => Document
  | "embed" => Embed
  | "font" => Font
  | "image" => Image
  | "manifest" => Manifest
  | "media" => Media
  | "object" => Object
  | "report" => Report
  | "script" => Script
  | "serviceworker" => ServiceWorker
  | "sharedworder" => SharedWorker
  | "style" => Style
  | "worker" => Worker
  | "xslt" => Xslt
  | e => raise(Failure("Unknown requestDestination: " ++ e));

type requestMode =
  | Navigate
  | SameOrigin
  | NoCORS
  | CORS;

let encodeRequestMode =
  /* internal */
  fun
  | Navigate => "navigate"
  | SameOrigin => "same-origin"
  | NoCORS => "no-cors"
  | CORS => "cors";

let decodeRequestMode =
  /* interna  */
  fun
  | "navigate" => Navigate
  | "same-origin" => SameOrigin
  | "no-cors" => NoCORS
  | "cors" => CORS
  | e => raise(Failure("Unknown requestMode: " ++ e));

type requestCredentials =
  | Omit
  | SameOrigin
  | Include;

let encodeRequestCredentials =
  /* internal */
  fun
  | Omit => "omit"
  | SameOrigin => "same-origin"
  | Include => "include";

let decodeRequestCredentials =
  /* internal */
  fun
  | "omit" => Omit
  | "same-origin" => SameOrigin
  | "imclude" => Include
  | e => raise(Failure("Unknown requestCredentials: " ++ e));

type requestCache =
  | Default
  | NoStore
  | Reload
  | NoCache
  | ForceCache
  | OnlyIfCached;

let encodeRequestCache =
  /* internal */
  fun
  | Default => "default"
  | NoStore => "no-store"
  | Reload => "reload"
  | NoCache => "no-cache"
  | ForceCache => "force-cache"
  | OnlyIfCached => "only-if-cached";

let decodeRequestCache =
  /* internal */
  fun
  | "default" => Default
  | "no-store" => NoStore
  | "reload" => Reload
  | "no-cache" => NoCache
  | "force-cache" => ForceCache
  | "only-if-cached" => OnlyIfCached
  | e => raise(Failure("Unknown requestCache: " ++ e));

type requestRedirect =
  | Follow
  | Error
  | Manual;

let encodeRequestRedirect =
  /* internal */
  fun
  | Follow => "follow"
  | Error => "error"
  | Manual => "manual";

let decodeRequestRedirect =
  /* internal */
  fun
  | "follow" => Follow
  | "error" => Error
  | "manual" => Manual
  | e => raise(Failure("Unknown requestRedirect: " ++ e));

module HeadersInit = {
  type t = headersInit;
  external make: Js.t({..}) => t = "%identity";
  external makeWithArray: array((string, string)) => t = "%identity";
};

module Headers = {
  type t = headers;
  [@bs.new] external make: t = "Headers";
  [@bs.new] external makeWithInit: headersInit => t = "Headers";
  [@bs.send.pipe: t] external append: string => string = "append";
  [@bs.send.pipe: t] external delete: string = "delete" /* very experimental */; /* entries */
  [@bs.send.pipe: t] [@bs.return {null_to_opt: null_to_opt}]
  external get: string => option(string) = "get";
  [@bs.send.pipe: t] external has: string => bool = "has" /* very experimental */; /* keys */
  [@bs.send.pipe: t] external set: (string, string) => unit = "set" /* very experimental */; /* values */
};

module BodyInit = {
  type t = bodyInit;
  external make: string => t = "%identity";
  external makeWithBlob: blob => t = "%identity";
  external makeWithBufferSource: bufferSource => t = "%identity";
  external makeWithFormData: formData => t = "%identity";
  external makeWithUrlSearchParams: urlSearchParams => t = "%identity";
};

module Body = {
  module Impl = (T: {type t;}) => {
    [@bs.get] external body: T.t => readableStream = "body";
    [@bs.get] external bodyUsed: T.t => bool = "bodyUsed";

    [@bs.send.pipe: T.t] external blob: Js.Promise.t(blob) = "blob";
    [@bs.send.pipe: T.t]
    external formData: Js.Promise.t(formData) = "formData";
    [@bs.send.pipe: T.t] external json: Js.Promise.t(Js.Json.t) = "json";
    [@bs.send.pipe: T.t] external text: Js.Promise.t(string) = "text";
  };
  type t = body;
  include Impl({
    type nonrec t = t;
  });
};

module RequestInit = {
  type t = requestInit;
  let map = f =>
    fun /* internal */
    | Some(v) => Some(f(v))
    | None => None;
  [@bs.obj]
  external make:
    (
      ~_method: string=?,
      ~headers: headersInit=?,
      ~body: bodyInit=?,
      ~referrer: string=?,
      ~referrerPolicy: string=?,
      ~mode: string=?,
      ~credentials: string=?,
      ~cache: string=?,
      ~redirect: string=?,
      ~integrity: string=?,
      ~keepalive: bool=?,
      ~timeout: int=?,
      unit
    ) =>
    requestInit =
    "";
  let make =
      (
        ~_method as method: option(requestMethod)=?,
        ~headers: option(headersInit)=?,
        ~body: option(bodyInit)=?,
        ~referrer: option(string)=?,
        ~referrerPolicy: referrerPolicy=None,
        ~mode: option(requestMode)=?,
        ~credentials: option(requestCredentials)=?,
        ~cache: option(requestCache)=?,
        ~redirect: option(requestRedirect)=?,
        ~integrity: string="",
        ~keepalive: option(bool)=?,
        ~timeout: option(int)=?,
      ) =>
    make(
      ~_method=?map(encodeRequestMethod, method),
      ~headers?,
      ~body?,
      ~referrer?,
      ~referrerPolicy=encodeReferrerPolicy(referrerPolicy),
      ~mode=?map(encodeRequestMode, mode),
      ~credentials=?map(encodeRequestCredentials, credentials),
      ~cache=?map(encodeRequestCache, cache),
      ~redirect=?map(encodeRequestRedirect, redirect),
      ~integrity,
      ~keepalive?,
      ~timeout?,
    );
};

module Request = {
  type t = request;
  include Body.Impl({
    type nonrec t = t;
  });
  [@bs.new] external make: string => t = "Request";
  [@bs.new] external makeWithInit: (string, requestInit) => t = "Request";
  [@bs.new] external makeWithRequest: t => t = "Request";
  [@bs.new] external makeWithRequestInit: (t, requestInit) => t = "Request";
  [@bs.get] external _method: t => string = "method";
  let method: t => requestMethod =
    self => decodeRequestMethod(_method(self));
  [@bs.get] external url: t => string = "url";
  [@bs.get] external headers: t => headers = "headers";
  [@bs.get] external type_: t => string = "type";
  let type_: t => requestType = self => decodeRequestType(type_(self));
  [@bs.get] external destination: t => string = "destination";
  let destination: t => requestDestination =
    self => decodeRequestDestination(destination(self));
  [@bs.get] external referrer: t => string = "referrer";
  [@bs.get] external referrerPolicy: t => string = "referrerPolicy";
  let referrerPolicy: t => referrerPolicy =
    self => decodeReferrerPolicy(referrerPolicy(self));
  [@bs.get] external mode: t => string = "mode";
  let mode: t => requestMode = self => decodeRequestMode(mode(self));
  [@bs.get] external credentials: t => string = "credentials";
  let credentials: t => requestCredentials =
    self => decodeRequestCredentials(credentials(self));
  [@bs.get] external cache: t => string = "cache";
  let cache: t => requestCache = self => decodeRequestCache(cache(self));
  [@bs.get] external redirect: t => string = "redirect";
  let redirect: t => requestRedirect =
    self => decodeRequestRedirect(redirect(self));
  [@bs.get] external integrity: t => string = "integrity";
  [@bs.get] external keepalive: t => bool = "keepalive";
  [@bs.get] external timeout: t => int = "timeout";
};

module Response = {
  type t = response;
  include Body.Impl({
    type nonrec t = t;
  });
  [@bs.val] external error: unit => t = "error";
  [@bs.val] external redirect: string => t = "redirect";
  [@bs.val]
  external redirectWithStatus: (string, int /* enum-ish */) => t = "redirect";
  [@bs.get] external headers: t => headers = "headers";
  [@bs.get] external ok: t => bool = "ok";
  [@bs.get] external redirected: t => bool = "redirected";
  [@bs.get] external status: t => int = "status";
  [@bs.get] external statusText: t => string = "statusText";
  [@bs.get] external _type: t => string = "type";
  [@bs.get] external url: t => string = "url";
  [@bs.send.pipe: t] external clone: t = "clone";
};

[@bs.module "node-fetch"]
external fetch: string => Js.Promise.t(response) = "default";

[@bs.module "node-fetch"]
external fetchWithInit: (string, requestInit) => Js.Promise.t(response) =
  "default";

[@bs.module "node-fetch"]
external fetchWithRequest: request => Js.Promise.t(response) = "default";

[@bs.module "node-fetch"]
external fetchWithRequestInit:
  (request, requestInit) => Js.Promise.t(response) =
  "default";