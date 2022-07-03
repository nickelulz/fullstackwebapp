import Express, { Request, Response } from 'express'
import logger from './logger'
import axios from 'axios'
import clic from 'cli-color'

const PORT = 3000;

const app = Express();
app.use(Express.static(__dirname + "/public/"));

function parse_ip(raw: string): string {
	return raw === '127.0.0.1' || raw.substring(7) === '127.0.0.1' || raw === '::1' ? '127.0.0.1' : raw;
}

app.listen(PORT, () => {
	logger.info(`Server now listening on port ${clic.green(PORT)}.`);
})

app.get('/', (req: Request, res: Response) => {
	const raw_ip = parse_ip(req.ip);
	const ip = raw_ip === '127.0.0.1' ? 'HOME' : raw_ip;
	logger.info(`Client ${clic.green(ip)} connected to ${clic.green('/')}.`);
	res.sendFile('index.html');
});

// Backend interfacing endpoint
app.get('/server', (req: Request, res: Response) => {
	res.send('Hello from frontend!');
	logger.info(`Recieved request from backend. (${clic.green('/server/')})`);
});

app.get('/get-ip', (req: Request, res: Response) => {
	const ip = parse_ip(req.ip);
	logger.info(`Recieved request from frontend for IP address ${clic.green(ip)}.`);
	res.send(ip);
});
