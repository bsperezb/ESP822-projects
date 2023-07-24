#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

const char* ssid = "TestESP";
const char* password = "test20091994";

ESP8266WebServer server(80);

char html[] PROGMEM = R"=====(
<!doctype html>
<html lang="en">

<head>
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1">
	<title>Toggle Led</title>
	<!-- <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css" rel="stylesheet"
		integrity="sha384-9ndCyUaIbzAi2FUVXJi0CjmCapSmO7SnpJef0486qhLnuZ2cdeRhO02iuK6FUUVM" crossorigin="anonymous"> -->
</head>

<body style="min-height:100vh; background-color:#a8bbce">
	<div class="container text-center">
		<div class="row align-items-start justify-content-center">
			<div class="col">
				<h1>Toggle LED</h1>
			</div>
		</div>
		<div class="row align-items-start justify-content-center">
			<div class="col-sm-6 col-12">
				<div class="card">
					<div class="justify-content-center align-items-center">
						<div type="button" onclick="toggleLED()" class="no-gutters">

							<div class="led" id="led"
								style="display: flex; justify-content: center; flex-direction: column; align-items: center; padding: 20px; background-color: rgb(237, 237, 154)">
								<div id="ledBig"
									style="border-radius: 50px 50px 25px 25px; width: 100px; height: 100px; background-color: yellow;border: 4px solid orange; display: flex; justify-content: center; align-items: center">
									<div id="ledSmall"
										style="border-radius: 25px 25px 12px 12px; width: 50px; height: 50px; border: 5px solid Orange; background-color: rgb(197, 120, 26)">
									</div>
								</div>
								<div
									style="border-radius: 0 0 0px 0px; width: 20px; height: 30px; background-color: black">
								</div>
							</div>
							<!-- <img id="imageLed" src="https://cdn-icons-png.flaticon.com/512/2338/2338838.png" width="300"
								style="max-width: 150px;" class="card-img-top" alt="..."> -->
						</div>
					</div>
					<div class="card-body">
						<h5 class="card-title">Cambiar Estado</h5>
						<p class="card-text">Al darle click al led Cambiaras el estado del led conectado al pin 16 D0
						</p>
					</div>
				</div>
			</div>
		</div>
	</div>
	<script>
		async function toggleLED() { try { const response = await fetch('/toggle'); const data = await response.text(); toggleImage(); console.log(data); } catch (error) { console.error(error); } }
		function toggleImage() { 
			const imageLed = document.querySelector("#imageLed"); 
			let led = document.querySelector('#led');
			let ledBig = document.querySelector('#ledBig');
			let colorOff = 'rgb(255, 255, 255)';
			let colorOn = 'rgb(237, 237, 154)';
			let colorOffBig = 'rgb(255, 255, 255)';
			let colorOnBig = 'yellow';
			if (led.style.backgroundColor == 'rgb(237, 237, 154)') {
				led.style.backgroundColor = colorOff;
				ledBig.style.backgroundColor = colorOffBig;
			} else {
				led.style.backgroundColor = colorOn;
				ledBig.style.backgroundColor = colorOnBig;
			}
			console.log(led.style.backgroundColor)
		}
	</script>
</body>
<style>
	:root {
		--bs-blue: #0d6efd;
		--bs-indigo: #6610f2;
		--bs-purple: #6f42c1;
		--bs-pink: #d63384;
		--bs-red: #dc3545;
		--bs-orange: #fd7e14;
		--bs-yellow: #ffc107;
		--bs-green: #198754;
		--bs-teal: #20c997;
		--bs-cyan: #0dcaf0;
		--bs-black: #000;
		--bs-white: #fff;
		--bs-gray: #6c757d;
		--bs-gray-dark: #343a40;
		--bs-gray-100: #f8f9fa;
		--bs-gray-200: #e9ecef;
		--bs-gray-300: #dee2e6;
		--bs-gray-400: #ced4da;
		--bs-gray-500: #adb5bd;
		--bs-gray-600: #6c757d;
		--bs-gray-700: #495057;
		--bs-gray-800: #343a40;
		--bs-gray-900: #212529;
		--bs-primary: #0d6efd;
		--bs-secondary: #6c757d;
		--bs-success: #198754;
		--bs-info: #0dcaf0;
		--bs-warning: #ffc107;
		--bs-danger: #dc3545;
		--bs-light: #f8f9fa;
		--bs-dark: #212529;
		--bs-primary-rgb: 13, 110, 253;
		--bs-secondary-rgb: 108, 117, 125;
		--bs-success-rgb: 25, 135, 84;
		--bs-info-rgb: 13, 202, 240;
		--bs-warning-rgb: 255, 193, 7;
		--bs-danger-rgb: 220, 53, 69;
		--bs-light-rgb: 248, 249, 250;
		--bs-dark-rgb: 33, 37, 41;
		--bs-primary-text-emphasis: #052c65;
		--bs-secondary-text-emphasis: #2b2f32;
		--bs-success-text-emphasis: #0a3622;
		--bs-info-text-emphasis: #055160;
		--bs-warning-text-emphasis: #664d03;
		--bs-danger-text-emphasis: #58151c;
		--bs-light-text-emphasis: #495057;
		--bs-dark-text-emphasis: #495057;
		--bs-primary-bg-subtle: #cfe2ff;
		--bs-secondary-bg-subtle: #e2e3e5;
		--bs-success-bg-subtle: #d1e7dd;
		--bs-info-bg-subtle: #cff4fc;
		--bs-warning-bg-subtle: #fff3cd;
		--bs-danger-bg-subtle: #f8d7da;
		--bs-light-bg-subtle: #fcfcfd;
		--bs-dark-bg-subtle: #ced4da;
		--bs-primary-border-subtle: #9ec5fe;
		--bs-secondary-border-subtle: #c4c8cb;
		--bs-success-border-subtle: #a3cfbb;
		--bs-info-border-subtle: #9eeaf9;
		--bs-warning-border-subtle: #ffe69c;
		--bs-danger-border-subtle: #f1aeb5;
		--bs-light-border-subtle: #e9ecef;
		--bs-dark-border-subtle: #adb5bd;
		--bs-white-rgb: 255, 255, 255;
		--bs-black-rgb: 0, 0, 0;
		--bs-font-sans-serif: system-ui, -apple-system, "Segoe UI", Roboto, "Helvetica Neue", "Noto Sans", "Liberation Sans", Arial, sans-serif, "Apple Color Emoji", "Segoe UI Emoji", "Segoe UI Symbol", "Noto Color Emoji";
		--bs-font-monospace: SFMono-Regular, Menlo, Monaco, Consolas, "Liberation Mono", "Courier New", monospace;
		--bs-gradient: linear-gradient(180deg, rgba(255, 255, 255, 0.15), rgba(255, 255, 255, 0));
		--bs-body-font-family: var(--bs-font-sans-serif);
		--bs-body-font-size: 1rem;
		--bs-body-font-weight: 400;
		--bs-body-line-height: 1.5;
		--bs-body-color: #212529;
		--bs-body-color-rgb: 33, 37, 41;
		--bs-body-bg: #fff;
		--bs-body-bg-rgb: 255, 255, 255;
		--bs-emphasis-color: #000;
		--bs-emphasis-color-rgb: 0, 0, 0;
		--bs-secondary-color: rgba(33, 37, 41, 0.75);
		--bs-secondary-color-rgb: 33, 37, 41;
		--bs-secondary-bg: #e9ecef;
		--bs-secondary-bg-rgb: 233, 236, 239;
		--bs-tertiary-color: rgba(33, 37, 41, 0.5);
		--bs-tertiary-color-rgb: 33, 37, 41;
		--bs-tertiary-bg: #f8f9fa;
		--bs-tertiary-bg-rgb: 248, 249, 250;
		--bs-heading-color: inherit;
		--bs-link-color: #0d6efd;
		--bs-link-color-rgb: 13, 110, 253;
		--bs-link-decoration: underline;
		--bs-link-hover-color: #0a58ca;
		--bs-link-hover-color-rgb: 10, 88, 202;
		--bs-code-color: #d63384;
		--bs-highlight-bg: #fff3cd;
		--bs-border-width: 1px;
		--bs-border-style: solid;
		--bs-border-color: #dee2e6;
		--bs-border-color-translucent: rgba(0, 0, 0, 0.175);
		--bs-border-radius: 0.375rem;
		--bs-border-radius-sm: 0.25rem;
		--bs-border-radius-lg: 0.5rem;
		--bs-border-radius-xl: 1rem;
		--bs-border-radius-xxl: 2rem;
		--bs-border-radius-2xl: var(--bs-border-radius-xxl);
		--bs-border-radius-pill: 50rem;
		--bs-box-shadow: 0 0.5rem 1rem rgba(0, 0, 0, 0.15);
		--bs-box-shadow-sm: 0 0.125rem 0.25rem rgba(0, 0, 0, 0.075);
		--bs-box-shadow-lg: 0 1rem 3rem rgba(0, 0, 0, 0.175);
		--bs-box-shadow-inset: inset 0 1px 2px rgba(0, 0, 0, 0.075);
		--bs-focus-ring-width: 0.25rem;
		--bs-focus-ring-opacity: 0.25;
		--bs-focus-ring-color: rgba(13, 110, 253, 0.25);
		--bs-form-valid-color: #198754;
		--bs-form-valid-border-color: #198754;
		--bs-form-invalid-color: #dc3545;
		--bs-form-invalid-border-color: #dc3545;
	}

	*,
	::after,
	::before {
		box-sizing: border-box;
	}

	@media (prefers-reduced-motion:no-preference) {
		:root {
			scroll-behavior: smooth;
		}
	}

	body {
		margin: 0;
		font-family: var(--bs-body-font-family);
		font-size: var(--bs-body-font-size);
		font-weight: var(--bs-body-font-weight);
		line-height: var(--bs-body-line-height);
		color: var(--bs-body-color);
		text-align: var(--bs-body-text-align);
		background-color: var(--bs-body-bg);
		-webkit-text-size-adjust: 100%;
		-webkit-tap-highlight-color: transparent;
	}

	h1,
	h5 {
		margin-top: 0;
		margin-bottom: .5rem;
		font-weight: 500;
		line-height: 1.2;
		color: var(--bs-heading-color);
	}

	h1 {
		font-size: calc(1.375rem + 1.5vw);
	}

	@media (min-width:1200px) {
		h1 {
			font-size: 2.5rem;
		}
	}

	h5 {
		font-size: 1.25rem;
	}

	p {
		margin-top: 0;
		margin-bottom: 1rem;
	}

	img {
		vertical-align: middle;
	}

	[type=button] {
		-webkit-appearance: button;
	}

	[type=button]:not(:disabled) {
		cursor: pointer;
	}

	.container {
		--bs-gutter-x: 1.5rem;
		--bs-gutter-y: 0;
		width: 100%;
		padding-right: calc(var(--bs-gutter-x) * .5);
		padding-left: calc(var(--bs-gutter-x) * .5);
		margin-right: auto;
		margin-left: auto;
	}

	@media (min-width:576px) {
		.container {
			max-width: 540px;
		}
	}

	@media (min-width:768px) {
		.container {
			max-width: 720px;
		}
	}

	@media (min-width:992px) {
		.container {
			max-width: 960px;
		}
	}

	@media (min-width:1200px) {
		.container {
			max-width: 1140px;
		}
	}

	@media (min-width:1400px) {
		.container {
			max-width: 1320px;
		}
	}

	:root {
		--bs-breakpoint-xs: 0;
		--bs-breakpoint-sm: 576px;
		--bs-breakpoint-md: 768px;
		--bs-breakpoint-lg: 992px;
		--bs-breakpoint-xl: 1200px;
		--bs-breakpoint-xxl: 1400px;
	}

	.row {
		--bs-gutter-x: 1.5rem;
		--bs-gutter-y: 0;
		display: flex;
		flex-wrap: wrap;
		margin-top: calc(-1 * var(--bs-gutter-y));
		margin-right: calc(-.5 * var(--bs-gutter-x));
		margin-left: calc(-.5 * var(--bs-gutter-x));
	}

	.row>* {
		flex-shrink: 0;
		width: 100%;
		max-width: 100%;
		padding-right: calc(var(--bs-gutter-x) * .5);
		padding-left: calc(var(--bs-gutter-x) * .5);
		margin-top: var(--bs-gutter-y);
	}

	.col {
		flex: 1 0 0%;
	}

	.col-12 {
		flex: 0 0 auto;
		width: 100%;
	}

	@media (min-width:576px) {
		.col-sm-6 {
			flex: 0 0 auto;
			width: 50%;
		}
	}

	.card {
		--bs-card-spacer-y: 1rem;
		--bs-card-spacer-x: 1rem;
		--bs-card-title-spacer-y: 0.5rem;
		--bs-card-border-width: var(--bs-border-width);
		--bs-card-border-color: var(--bs-border-color-translucent);
		--bs-card-border-radius: var(--bs-border-radius);
		--bs-card-inner-border-radius: calc(var(--bs-border-radius) - (var(--bs-border-width)));
		--bs-card-cap-padding-y: 0.5rem;
		--bs-card-cap-padding-x: 1rem;
		--bs-card-cap-bg: rgba(var(--bs-body-color-rgb), 0.03);
		--bs-card-bg: var(--bs-body-bg);
		--bs-card-img-overlay-padding: 1rem;
		--bs-card-group-margin: 0.75rem;
		position: relative;
		display: flex;
		flex-direction: column;
		min-width: 0;
		height: var(--bs-card-height);
		color: var(--bs-body-color);
		word-wrap: break-word;
		background-color: var(--bs-card-bg);
		background-clip: border-box;
		border: var(--bs-card-border-width) solid var(--bs-card-border-color);
		border-radius: var(--bs-card-border-radius);
	}

	.card-body {
		flex: 1 1 auto;
		padding: var(--bs-card-spacer-y) var(--bs-card-spacer-x);
		color: var(--bs-card-color);
	}

	.card-title {
		margin-bottom: var(--bs-card-title-spacer-y);
		color: var(--bs-card-title-color);
	}

	.card-text:last-child {
		margin-bottom: 0;
	}

	.card-img-top {
		width: 100%;
	}

	.card-img-top {
		border-top-left-radius: var(--bs-card-inner-border-radius);
		border-top-right-radius: var(--bs-card-inner-border-radius);
	}

	.justify-content-center {
		justify-content: center !important;
	}

	.align-items-start {
		align-items: flex-start !important;
	}

	.align-items-center {
		align-items: center !important;
	}

	.text-center {
		text-align: center !important;
	}

	/*! CSS Used from: chrome-extension://mhnlakgilnojmhinhkckjpncpbhabphi/content.css */
	#USE_CHAT_GPT_AI_ROOT {
		position: fixed;
		top: 0;
		right: 0;
		height: 100vh;
		box-sizing: border-box;
		display: flex !important;
		flex-direction: column;
		opacity: 0;
		transition: all 0.1s ease-in-out;
		z-index: -2147483600;
	}

	use-chat-gpt-ai-content-menu,
	use-chat-gpt-ai,
	#USE_CHAT_GPT_AI_ROOT {
		visibility: visible !important;
	}

	:root {
		--contexify-zIndex: 666;
		--contexify-menu-minWidth: 220px;
		--contexify-menu-padding: 6px;
		--contexify-menu-radius: 6px;
		--contexify-menu-bgColor: #fff;
		--contexify-menu-shadow: 1px 2px 2px rgba(0, 0, 0, 0.1), 2px 4px 4px rgba(0, 0, 0, 0.1), 3px 6px 6px rgba(0, 0, 0, 0.1);
		--contexify-menu-negatePadding: var(--contexify-menu-padding);
		--contexify-separator-color: rgba(0, 0, 0, 0.2);
		--contexify-separator-margin: 5px;
		--contexify-itemContent-padding: 6px;
		--contexify-activeItem-radius: 4px;
		--contexify-item-color: #333;
		--contexify-activeItem-color: #fff;
		--contexify-activeItem-bgColor: #3498db;
		--contexify-rightSlot-color: #6f6e77;
		--contexify-activeRightSlot-color: #fff;
		--contexify-arrow-color: #6f6e77;
		--contexify-activeArrow-color: #fff;
	}

	:root {
		--contexify-item-color: rgba(0, 0, 0, 0.87) !important;
		--contexify-activeItem-color: rgba(0, 0, 0, 0.87) !important;
		--contexify-activeArrow-color: rgba(0, 0, 0, 0.87) !important;
		--contexify-activeItem-bgColor: rgba(118, 1, 211, 0.04) !important;
	}

	/*! CSS Used from: Embedded */
	*,
	::after,
	::before {
		box-sizing: border-box;
	}

	body {
		margin: 0;
		font-family: var(--bs-body-font-family);
		font-size: var(--bs-body-font-size);
		font-weight: var(--bs-body-font-weight);
		line-height: var(--bs-body-line-height);
		color: var(--bs-body-color);
		text-align: var(--bs-body-text-align);
		background-color: var(--bs-body-bg);
		-webkit-text-size-adjust: 100%;
		-webkit-tap-highlight-color: transparent;
	}

	h1,
	h5 {
		margin-top: 0;
		margin-bottom: .5rem;
		font-weight: 500;
		line-height: 1.2;
		color: var(--bs-heading-color);
	}

	h1 {
		font-size: calc(1.375rem + 1.5vw);
	}

	@media (min-width:1200px) {
		h1 {
			font-size: 2.5rem;
		}
	}

	h5 {
		font-size: 1.25rem;
	}

	p {
		margin-top: 0;
		margin-bottom: 1rem;
	}

	img {
		vertical-align: middle;
	}

	[type=button] {
		-webkit-appearance: button;
	}

	[type=button]:not(:disabled) {
		cursor: pointer;
	}

	.container {
		--bs-gutter-x: 1.5rem;
		--bs-gutter-y: 0;
		width: 100%;
		padding-right: calc(var(--bs-gutter-x) * .5);
		padding-left: calc(var(--bs-gutter-x) * .5);
		margin-right: auto;
		margin-left: auto;
	}

	@media (min-width:576px) {
		.container {
			max-width: 540px;
		}
	}

	@media (min-width:768px) {
		.container {
			max-width: 720px;
		}
	}

	@media (min-width:992px) {
		.container {
			max-width: 960px;
		}
	}

	@media (min-width:1200px) {
		.container {
			max-width: 1140px;
		}
	}

	@media (min-width:1400px) {
		.container {
			max-width: 1320px;
		}
	}

	.row {
		--bs-gutter-x: 1.5rem;
		--bs-gutter-y: 0;
		display: flex;
		flex-wrap: wrap;
		margin-top: calc(-1 * var(--bs-gutter-y));
		margin-right: calc(-.5 * var(--bs-gutter-x));
		margin-left: calc(-.5 * var(--bs-gutter-x));
	}

	.row>* {
		flex-shrink: 0;
		width: 100%;
		max-width: 100%;
		padding-right: calc(var(--bs-gutter-x) * .5);
		padding-left: calc(var(--bs-gutter-x) * .5);
		margin-top: var(--bs-gutter-y);
	}

	.col {
		flex: 1 0 0%;
	}

	.col-12 {
		flex: 0 0 auto;
		width: 100%;
	}

	@media (min-width:576px) {
		.col-sm-6 {
			flex: 0 0 auto;
			width: 50%;
		}
	}

	.card {
		--bs-card-spacer-y: 1rem;
		--bs-card-spacer-x: 1rem;
		--bs-card-title-spacer-y: 0.5rem;
		--bs-card-border-width: var(--bs-border-width);
		--bs-card-border-color: var(--bs-border-color-translucent);
		--bs-card-border-radius: var(--bs-border-radius);
		--bs-card-inner-border-radius: calc(var(--bs-border-radius) - (var(--bs-border-width)));
		--bs-card-cap-padding-y: 0.5rem;
		--bs-card-cap-padding-x: 1rem;
		--bs-card-cap-bg: rgba(var(--bs-body-color-rgb), 0.03);
		--bs-card-bg: var(--bs-body-bg);
		--bs-card-img-overlay-padding: 1rem;
		--bs-card-group-margin: 0.75rem;
		position: relative;
		display: flex;
		flex-direction: column;
		min-width: 0;
		height: var(--bs-card-height);
		color: var(--bs-body-color);
		word-wrap: break-word;
		background-color: var(--bs-card-bg);
		background-clip: border-box;
		border: var(--bs-card-border-width) solid var(--bs-card-border-color);
		border-radius: var(--bs-card-border-radius);
	}

	.card-body {
		flex: 1 1 auto;
		padding: var(--bs-card-spacer-y) var(--bs-card-spacer-x);
		color: var(--bs-card-color);
	}

	.card-title {
		margin-bottom: var(--bs-card-title-spacer-y);
		color: var(--bs-card-title-color);
	}

	.card-text:last-child {
		margin-bottom: 0;
	}

	.card-img-top {
		width: 100%;
	}

	.card-img-top {
		border-top-left-radius: var(--bs-card-inner-border-radius);
		border-top-right-radius: var(--bs-card-inner-border-radius);
	}

	.justify-content-center {
		justify-content: center !important;
	}

	.align-items-start {
		align-items: flex-start !important;
	}

	.align-items-center {
		align-items: center !important;
	}

	.text-center {
		text-align: center !important;
	}

	#USE_CHAT_GPT_AI_ROOT {
		position: fixed;
		top: 0;
		right: 0;
		height: 100vh;
		box-sizing: border-box;
		display: flex !important;
		flex-direction: column;
		opacity: 0;
		transition: all 0.1s ease-in-out;
		z-index: -2147483600;
	}

	use-chat-gpt-ai-content-menu,
	use-chat-gpt-ai,
	#USE_CHAT_GPT_AI_ROOT {
		visibility: visible !important;
	}
</style>
</html>
  )=====";

void handleRoot() {
  server.send(200, "text/html", html);
}

void handleToggle() {
  // digitalWrite(16, !digitalRead(16));
  if (digitalRead(16) == HIGH) {
    digitalWrite(16, LOW);
  } else {
    digitalWrite(16, HIGH);
  }
  server.send(200, "text/plain", "El pin 16 se ha cambiado");
  Serial.println(digitalRead(16));
}

void setup() {
  pinMode(16, OUTPUT);
  Serial.begin(115200);
  WiFi.softAP("LeenX2", "123456789");
  // crear conexion a la red
  // Conexión a Internet
  // WiFi.begin("Leen", "12345678");

// Esperar a que se conecte a Internet
  // while (WiFi.status() != WL_CONNECTED) {
    // delay(500);
    // Serial.print(".");
  // }

  Serial.print("Punto de acceso WiFi creado con éxito. Dirección IP: ");
  Serial.println(WiFi.softAPIP());
  digitalWrite(16, HIGH);
  server.on("/", handleRoot);
  server.on("/toggle", handleToggle);
  server.begin();
}

void loop() {
  server.handleClient();
}